export module Tetragrama.Helpers:UIDispatcher;

import std;
import ZEngine;

namespace Tetragrama::Helpers
{
    struct UIDispatcher
    {
        using Action = std::function<void(void)>;

        static void RunAsync(Action action)
        {
            ZEngine::Helpers::ThreadPoolHelper::Submit(action);
        }
    };
} // namespace Tetragrama::Helpers
