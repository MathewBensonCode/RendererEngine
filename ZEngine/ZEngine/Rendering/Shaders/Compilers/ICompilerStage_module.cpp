export module ZEngine.Rendering.Shaders.Compilers.ICompilerStage;

import std;
import ZEngine.Core.IPipeline;
import ZEngine.Rendering.Shaders.ShaderInformation;

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
