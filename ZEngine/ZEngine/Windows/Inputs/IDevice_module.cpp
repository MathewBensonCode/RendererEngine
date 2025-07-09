export module ZEngine.Windows:Inputs.IDevice;

import std;
import :Inputs.KeyCode;
import ZEngine.Core.Memory.Allocator;
import ZEngine.ZEngineDef;
import :CoreWindow;

export namespace ZEngine::Windows::Inputs
{

    struct IDevice
    {
        IDevice(const char* name = "abstract_device") : m_name(name) {}
        virtual ~IDevice() = default;
        const char*                                    m_name;
        static Core::Memory::ArenaAllocator*           Arena;
        static std::map<const char*, IDevice*> Devices;

        static void                                    Initialize(Core::Memory::ArenaAllocator* arena)
        {
            Arena = arena;
        }

        template <typename T, typename = std::enable_if_t<std::is_base_of_v<IDevice, T>>>
        static const T* As() noexcept
        {
            const std::type_info& type = typeid(T);
            auto                  it   = Devices.find(type.name());

            if (it != std::end(Devices))
            {
                return reinterpret_cast<T*>(it->second);
            }

            IDevice* device = ZPushStructCtor<T>(Arena);
            auto     pair   = Devices.emplace(std::make_pair(type.name(), device));
            return reinterpret_cast<T*>(pair.first->second);
        }

        virtual bool        IsKeyPressed(ZEngine::Windows::Inputs::GlfwKeyCode key, ZEngine::Windows::CoreWindow* const window) const  = 0;

        virtual bool        IsKeyReleased(ZEngine::Windows::Inputs::GlfwKeyCode key, Windows::CoreWindow* const window) const = 0;

        virtual const char* GetName() const
        {
            return m_name;
        }
    };

    std::map<const char*, IDevice*> IDevice::Devices = {};
    Core::Memory::ArenaAllocator*           IDevice::Arena   = nullptr;
} // namespace ZEngine::Windows::Inputs
