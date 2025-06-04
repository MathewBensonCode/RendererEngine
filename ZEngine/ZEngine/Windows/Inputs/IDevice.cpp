module ZEngine.Windows.Inputs.IDevice;

import std;

namespace ZEngine::Windows::Inputs
{
    std::map<const char*, IDevice*> IDevice::Devices = {};
    Core::Memory::ArenaAllocator*           IDevice::Arena   = nullptr;
} // namespace ZEngine::Windows::Inputs
