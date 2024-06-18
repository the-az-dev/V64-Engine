#ifndef V64_ENGINE_OBJECT_H
#define V64_ENGINE_OBJECT_H

namespace V64Engine::Game{

    class Object {
    public:
        Object(float x, float y, float z = 0); //need to re-organize for 3D models
        virtual ~Object() = default;

        virtual void update(float deltaTime) = 0;
        virtual void render() = 0;

    protected:
        float x, y, z;
    };

}
// V64Engine

#endif //V64_ENGINE_OBJECT_H
