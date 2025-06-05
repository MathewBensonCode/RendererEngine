module ZEngine.Rendering.Shaders.Compilers.ShaderCompiler;

import ZEngine.Core.Coroutine;
import ZEngine.Logging.Logger;
import ZEngine.Rendering.Shaders.Compilers.CompilationStage;
import ZEngine.Rendering.Shaders.ShaderReader;
import ZEngine.Rendering.Shaders.ShaderIncluder;
import ZEngine.Helpers.IntrusivePtr;
import ZEngine.Rendering.Shaders.Compilers.ICompilerStage;

using namespace ZEngine::Helpers;

namespace ZEngine::Rendering::Shaders::Compilers
{

    ShaderCompiler::ShaderCompiler()
    {
        m_reader = CreateScope<ShaderReader>();
        m_stage  = CreateRef<CompilationStage>();

        m_stage->SetContext(this);
    }

    ShaderCompiler::ShaderCompiler(std::string_view filename) : m_source_file(filename)
    {
        m_reader = CreateScope<ShaderReader>();
        m_stage  = CreateRef<CompilationStage>();

        m_stage->SetContext(this);
    }

    ShaderCompiler::~ShaderCompiler() {}

    void ShaderCompiler::SetSource(std::string_view filename)
    {
        m_source_file = filename.data();
    }

    std::future<ShaderCompilerResult> ShaderCompiler::CompileAsync()
    {
        std::unique_lock      lock(m_mutex);

        ShaderOperationResult read_operation = co_await m_reader->ReadAsync(m_source_file);
        if (read_operation == ShaderOperationResult::FAILURE)
        {
            ZEngine::Logging::Logger::Critical(std::format("Compilation process stopped"));
            co_return ShaderCompilerResult{ShaderOperationResult::FAILURE, ShaderInformation{}};
        }

        ShaderInformation shader_information = m_reader->GetInformations();

        while (m_running_stages)
        {
            ICompilerStage* stage = reinterpret_cast<ICompilerStage*>(m_stage.get());
            co_await stage->RunAsync(shader_information);

            const auto& stage_info = stage->GetInformation();

            if (!stage_info.IsSuccess)
            {
                // Log the critical error or perform any necessary cleanup
                ZEngine::Logging::Logger::Critical(std::format("Compilation process encountered a failure at stage ..."));;
                co_return ShaderCompilerResult{ShaderOperationResult::FAILURE, ShaderInformation{}};
            }

            if (m_stage->HasNext())
            {
                m_stage->Next();
            }
            else
            {
                m_running_stages = false;
            }
        }
        co_return ShaderCompilerResult{ShaderOperationResult::SUCCESS, std::move(shader_information)};
    }
} // namespace ZEngine::Rendering::Shaders::Compilers
