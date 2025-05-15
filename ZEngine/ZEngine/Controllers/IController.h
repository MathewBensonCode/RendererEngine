#pragma once

#include <ZEngine/Core/IEventable.h>
#include <ZEngine/Core/IInitializable.h>
#include <ZEngine/Core/IRenderable.h>
#include <ZEngine/Core/IUpdatable.h>
#include <ZEngine/Helpers/IntrusivePtr.h>

namespace ZEngine::Controllers
{
    struct IController : public Core::IInitializable, public Core::IUpdatable, public Core::IEventable, public Helpers::RefCounted
    {
        IController()  = default;
        ~IController() = default;
    };
} // namespace ZEngine::Controllers
