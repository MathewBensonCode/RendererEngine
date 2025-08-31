import ZEngine;

namespace Tetragrama::Controllers
{
    struct IController : public ZEngine::Core::IUpdatable, public ZEngine::Core::IEventable
    {
        IController()  = default;
        ~IController() = default;
    };
} // namespace Tetragrama::Controllers
