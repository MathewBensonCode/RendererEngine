export module ZEngine.Core.CoroutineScheduler;

import std;
import ZEngine.Helpers.IntrusivePtr;
import ZEngine.Helpers.ThreadSafeQueue;
import ZEngine.ZEngineDef;

export namespace ZEngine::Core
{
    struct CoroutineAction : public Helpers::RefCounted
    {
        using ReadyCallback    = std::function<bool(void)>;
        using ExecuteCallback  = std::function<void(void)>;

        ReadyCallback   Ready  = nullptr;
        ExecuteCallback Action = nullptr;

        operator bool() noexcept
        {
            return (Ready && Action);
        }
    };

    struct CoroutineScheduler
    {
        using SchedulerQueue = Helpers::ThreadSafeQueue<CoroutineAction>;

        static void Schedule(CoroutineAction&& action);

    private:
        static std::atomic_bool                                        s_running;
        static Helpers::Ref<Helpers::ThreadSafeQueue<CoroutineAction>> s_action_queue;

        static void                                                    Start();
        static void                                                    Run(Helpers::WeakRef<SchedulerQueue> queue);
    };

} // namespace ZEngine::Core
