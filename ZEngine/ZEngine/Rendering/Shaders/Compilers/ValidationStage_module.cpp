module;
#include <spirv-tools/libspirv.hpp>
#include <spirv-tools/optimizer.hpp>

export module ZEngine.Rendering:Shaders.Compilers.ValidationStage;

import std;
import :Shaders.Compilers.ICompilerStage;
import :Shaders.ShaderInformation;

export namespace ZEngine::Rendering::Shaders::Compilers
{

    class ValidationStage : public ICompilerStage
    {
    public:
        /**
         * Initialize a new ValidationStage instance.
         */
        ValidationStage();
        virtual ~ValidationStage();

        /**
         * Run asynchronously compiler stage
         *
         * @param information Collection of shader information
         */
        virtual std::future<void> RunAsync(ShaderInformation& information) override;
    };
} // namespace ZEngine::Rendering::Shaders::Compilers
