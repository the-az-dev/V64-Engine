#include "../include/event.h"

namespace V64Engine::Core {
    void Event::addEventListener(V64Engine::Core::Event::EventCallback callback) {
        eventCallbacks.push_back(callback);
    }

    void Event::processEvents() {
        for (auto& callback : eventCallbacks) {
            callback();
        }
    }
}
// V64Engine