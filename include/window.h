#ifndef V64_ENGINE_WINDOW_H
#define V64_ENGINE_WINDOW_H

#include "iostream"
#include "GLFW/glfw3.h"

namespace V64Engine::Core{
    class Window{
    public:
        Window(const std::string& title, int width, int height);
        ~Window();

        static void clear();
        void display();
        bool isOpen() const;
        static void pollEvent();

    private:
        GLFWwindow* window;
    };
}

// V64Engine

#endif //V64_ENGINE_WINDOW_H
