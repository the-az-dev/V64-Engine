#ifndef V64ENGINE_CAMERA_H
#define V64ENGINE_CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace V64Engine::Game {
    class Camera {
    public:
        Camera(glm::vec3 position, glm::vec3 target, glm::vec3 up);

        void SetPosition(const glm::vec3 &position);

        void SetTarget(const glm::vec3 &target);

        void SetUp(const glm::vec3 &up);

        glm::mat4 GetViewMatrix() const;

    private:
        glm::vec3 position_;
        glm::vec3 target_;
        glm::vec3 up_;
    };
}
#endif //V64ENGINE_CAMERA_H
