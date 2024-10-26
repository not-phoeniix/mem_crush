#pragma once

#include <glm/glm.hpp>

using namespace glm;

class Camera {
   private:
    vec3 position;
    vec3 rotation;

   public:
    Camera();
    Camera(vec3 position);
    Camera(vec3 position, vec3 rotation);

    /// @brief Gets the position vector of this camera in the world
    /// @return Vec3 copy of position of camera
    vec3 get_position();

    /// @brief Sets the position of this mesh in the world
    /// @param position New world position vector to set
    void set_position(vec3 position);

    /// @brief Gets the rotation vector of this camera in the world
    /// @return Vec3 copy of rotation of camera
    vec3 get_rotation();

    /// @brief Sets the position vector of this camera in the world
    /// @param rotation New rotation vector to set
    void set_rotation(vec3 rotation);
};
