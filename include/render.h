#ifndef V64_ENGINE_RENDER_H
#define V64_ENGINE_RENDER_H

#include "window.h"
#include "object.h"
#include <vector>
#include <memory>

namespace V64Engine::Core {

    class Renderer {
    public:
        Renderer(Window& window);
        void addObject(std::shared_ptr<V64Engine::Game::Object> object);
        void renderAll();
    private:
        Window& window;
        std::vector<std::shared_ptr<V64Engine::Game::Object>> objects;
    };

}
// V64Engine

#endif //V64_ENGINE_RENDER_H
