module;
#include <glslang/Public/ShaderLang.h>

export module ZEngine.Rendering:Shaders.ShaderReader;

import std;
import :Shaders.ShaderInformation;
import :Shaders.ShaderEnums;

export namespace ZEngine::Rendering::Shaders
{

    class ShaderReader
    {
    public:
        /**
         * Initializes a new ShaderReader instance.
         */
        ShaderReader();
        ~ShaderReader();

        static std::vector<std::uint32_t>       ReadAsBinary(std::filesystem::path filename);

        /**
         * Read asynchronously content of shader file
         *
         * @param filename  Path to the shader file
         * @return enum ShaderReaderState that describes the read operation state
         */
        std::future<ShaderOperationResult> ReadAsync(std::filesystem::path filename);

        /**
         * Get shaders information collected during Reading process
         *
         * @see Read(std::string_view) and ReadAsync(std::string_view) methods
         * @return ShaderInformation
         */
        const ShaderInformation&           GetInformations() const;

        /**
         * Get shaders information collected during Reading process
         *
         * @see Read(std::string_view) and ReadAsync(std::string_view) methods
         * @return ShaderInformation
         */
        ShaderInformation&                 GetInformations();
        ShaderType                         GetShaderType(const std::filesystem::path& path);

    private:
        std::ifstream     m_filestream{};
        ShaderInformation m_shader_info_collection{};
        std::mutex        m_lock;
    };
} // namespace ZEngine::Rendering::Shaders
