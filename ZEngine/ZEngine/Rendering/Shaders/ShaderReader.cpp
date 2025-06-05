module ZEngine.Rendering.Shaders.ShaderReader;

import ZEngine.Core.Coroutine;
import ZEngine.Logging.Logger;
import ZEngine.ZEngineDef;

namespace ZEngine::Rendering::Shaders
{

    ShaderReader::ShaderReader() {}

    ShaderReader::~ShaderReader()
    {
        if (m_filestream.is_open())
        {
            m_filestream.close();
        }
    }

    std::vector<std::uint32_t> ShaderReader::ReadAsBinary(std::filesystem::path filename)
    {
        std::ifstream file_stream = {};
        file_stream.open(filename, std::ifstream::binary | std::ifstream::ate);
        if (!file_stream.is_open())
        {
            ZEngine::Logging::Logger::Error(std::format("====== Shader file : {} cannot be opened ======", filename.string()));
            ZENGINE_EXIT_FAILURE();
        }

        std::size_t                buffer_size = static_cast<std::size_t>(file_stream.tellg());
        std::vector<std::uint32_t> buffer(buffer_size / 4);
        file_stream.seekg(std::ifstream::beg);
        file_stream.read(reinterpret_cast<char*>(buffer.data()), buffer_size);
        file_stream.close();

        return buffer;
    }

    ShaderType ShaderReader::GetShaderType(const std::filesystem::path& path)
    {
        if (path.extension() == ".vert")
            return ShaderType::VERTEX;
        if (path.extension() == ".frag")
            return ShaderType::FRAGMENT;
        if (path.extension() == ".geom")
            return ShaderType::GEOMETRY;
        return ShaderType::UNKNOWN;
    }

    std::future<ShaderOperationResult> ShaderReader::ReadAsync(std::filesystem::path filename)
    {
        std::unique_lock<std::mutex> lock(m_lock);

        m_filestream.open(filename, std::ifstream::in);
        if (!m_filestream.is_open())
        {
            ZEngine::Logging::Logger::Error(std::format("====== Shader file : {} cannot be opened ======", filename.string()));
            co_return ShaderOperationResult::FAILURE;
        }

        std::streamsize size = m_filestream.tellg();
        m_filestream.seekg(0, std::ios::beg);

        std::string buffer;
        buffer.reserve(size);

        buffer.assign((std::istreambuf_iterator<char>(m_filestream)), std::istreambuf_iterator<char>());

        m_shader_info_collection.Source = std::move(buffer);
        m_shader_info_collection.Name   = filename.stem().string();
        m_shader_info_collection.Type   = GetShaderType(filename);

        if (m_shader_info_collection.Type == ShaderType::UNKNOWN)
        {
            ZEngine::Logging::Logger::Error(std::format("====== Shader file : {} unsupported format ======", filename.string()));
            co_return ShaderOperationResult::FAILURE;
        }

        ZEngine::Logging::Logger::Info(std::format("====== Shader file : {} read succeeded ======", filename.string()));
        m_filestream.close();
        co_return ShaderOperationResult::SUCCESS;
    }

    const ShaderInformation& ShaderReader::GetInformations() const
    {
        return m_shader_info_collection;
    }

    ShaderInformation& ShaderReader::GetInformations()
    {
        return m_shader_info_collection;
    }
} // namespace ZEngine::Rendering::Shaders
