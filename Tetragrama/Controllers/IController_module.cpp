export module Tetragrama.Controllers:IController;

import ZEngine;

namespace Tetragrama::Controllers
{
    struct IController : public ZEngine::Rendering::Windows::IUpdatable, public ZEngine::Rendering::IEventable
    {
        IController()  = default;
        ~IController() = default;
    };
} // namespace Tetragrama::Controllers
