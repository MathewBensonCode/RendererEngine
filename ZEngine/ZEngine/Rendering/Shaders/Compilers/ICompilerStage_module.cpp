export module ZEngine.Rendering:Shaders.Compilers.ICompilerStage;

import std;
import :Shaders.ShaderInformation;
import ZEngine.Core.IPipeline;

export namespace ZEngine::Rendering::Shaders::Compilers
{

    struct ICompilerStage : public Core::IPipelineStage
    {

        /**
         * Initialize a new ICompilerStage instance.
         */
        ICompilerStage()                                                   = default;
        virtual ~ICompilerStage()                                          = default;

        /**
         * Run asynchronously compiler stage
         *
         * @param information Collection of shader information
         */
        virtual std::future<void> RunAsync(ShaderInformation& information) = 0;

    protected:
        std::recursive_mutex m_mutex;
    };
} // namespace ZEngine::Rendering::Shaders::Compilers
