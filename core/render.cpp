#include "../include/render.h"

namespace V64Engine::Core {

    Renderer::Renderer(Window& window)
            : window(window) {}

    void Renderer::addObject(std::shared_ptr<V64Engine::Game::Object> object) {
        objects.push_back(object);
    }

    void Renderer::renderAll() {
        window.clear();
        for (auto& object : objects) {
            object->render();
        }
        window.display();
    }
}
// V64Engine