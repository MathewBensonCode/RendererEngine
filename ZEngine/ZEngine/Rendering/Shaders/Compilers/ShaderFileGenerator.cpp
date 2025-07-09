module ZEngine.Rendering;

import std;
import :Shaders.Compilers.ShaderFileGenerator;
import ZEngine.Core.Coroutine;
import ZEngine.Logging;

namespace ZEngine::Rendering::Shaders::Compilers
{

    ShaderFileGenerator::ShaderFileGenerator()
    {
        // check if output dir exists if not create the folder
        if (!std::filesystem::exists(std::filesystem::path(outputDirectory)))
        {
            if (!std::filesystem::create_directories(std::filesystem::path(outputDirectory)))
            {
                m_information = {false, "Failed to create output directory "};
            }
        }
    }

    ShaderFileGenerator::~ShaderFileGenerator() {}

    std::string ShaderFileGenerator::OutputName(ShaderInformation& information_list)
    {
        std::filesystem::path file_path;
        if (information_list.Type == ShaderType::VERTEX)
            file_path = std::filesystem::path(std::format("{}/{}_vertex.spv", outputDirectory, information_list.Name));
        if (information_list.Type == ShaderType::FRAGMENT)
            file_path = std::filesystem::path(std::format("{}/{}_fragment.spv", outputDirectory, information_list.Name));

        return file_path.string();
    }

    std::future<void> ShaderFileGenerator::RunAsync(ShaderInformation& information_list)
    {
        std::unique_lock lock(m_mutex);
        std::string      output_file = OutputName(information_list);
        std::ofstream    out(output_file, std::ios::out | std::ios::binary);
        if (!out.is_open() || !out)
        {
            m_information = {false, "Failed to open spriv file: " + output_file};
            co_return;
        }
        out.write(reinterpret_cast<const char*>(information_list.BinarySource.data()), information_list.BinarySource.size() * sizeof(std::uint32_t));

        co_return;
    }
} // namespace ZEngine::Rendering::Shaders::Compilers
