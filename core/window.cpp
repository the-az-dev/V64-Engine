#include "../include/window.h"
#include "stdexcept"

namespace V64Engine::Core{
    Window::Window(const std::string& title, int width, int height){
        if (!glfwInit()) {
            throw std::runtime_error("Failed to initialize GLFW");
        }

        window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        if (!window) {
            glfwTerminate();
            throw std::runtime_error("Failed to create GLFW window");
        }

        glfwMakeContextCurrent(window);

        glViewport(0, 0, width, height);
    }

    Window::~Window(){
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void Window::clear() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Window::display() {
        glfwSwapBuffers(window);
    }

    bool  Window::isOpen() const {
        return !glfwWindowShouldClose(window);
    }

    void Window::pollEvent() {
        glfwPollEvents();
    }
}



// V64Engine