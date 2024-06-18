#ifndef V64_ENGINE_EVENT_H
#define V64_ENGINE_EVENT_H

#include <functional>
#include <vector>

namespace V64Engine::Core {

    class Event {
    public:
        using EventCallback = std::function<void()>;

        void addEventListener(EventCallback callback);
        void processEvents();

    private:
        std::vector<EventCallback> eventCallbacks;
    };

}
// V64Engine

#endif //V64_ENGINE_EVENT_H
