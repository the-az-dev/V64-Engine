#include "../include/camera.h"


// РОЗІБРАТИСЬ ІЗ ПІДКЛЮЧЕННЯМ І ЗІБРАННЯМ ДЖЛМ ТА
//ВИКОРИСТАННЯМ ДАНОГО ОБДЖЕКТУ В СВОЄМУ ПРОЕКТІ

namespace V64Engine::Game {

    Camera::Camera(glm::vec3 position, glm::vec3 target, glm::vec3 up)
            : position_(position), target_(target), up_(up) {}

    void Camera::SetPosition(const glm::vec3 &position) {
        position_ = position;
    }

    void Camera::SetTarget(const glm::vec3 &target) {
        target_ = target;
    }

    void Camera::SetUp(const glm::vec3 &up) {
        up_ = up;
    }

    glm::mat4 Camera::GetViewMatrix() const {
        return glm::lookAt(position_, target_, up_);
    }
}