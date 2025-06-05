export module ZEngine.Rendering.Shaders.Compilers.ShaderCompiler;

import std;
import ZEngine.Core.IPipeline;
import ZEngine.Helpers.IntrusivePtr;
import ZEngine.Rendering.Shaders.ShaderReader;
import ZEngine.Rendering.Shaders.ShaderInformation;
import ZEngine.Rendering.Shaders.ShaderEnums;

export namespace ZEngine::Rendering::Shaders::Compilers
{
    struct ShaderCompilerResult
    {
        ShaderOperationResult OperationResult;
        ShaderInformation     Information;
    };

    class ShaderCompiler : public Core::IPipelineContext
    {
    public:
        /**
         * Initialize a new ShaderCompiler instance.
         */
        ShaderCompiler();
        ShaderCompiler(std::string_view filename);
        ~ShaderCompiler();

        /**
         * Set the shader source file
         * @param filename Path of the shader file
         */
        void                              SetSource(std::string_view filename);

        /**
         * Compile shader source code
         * @return Tuple of <ShaderOperationResult, ShaderInformation> that represents status of the compile process
         *(Success or Failure) and the Shader Information
         */

        std::future<ShaderCompilerResult> CompileAsync();

    private:
        std::string                  m_source_file;
        Helpers::Scope<ShaderReader> m_reader{nullptr};
        std::recursive_mutex         m_mutex;
    };
} // namespace ZEngine::Rendering::Shaders::Compilers
