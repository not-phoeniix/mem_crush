#pragma once

#include <glm/glm.hpp>

using namespace glm;

class Camera {
   private:
    vec3 position;
    float yaw;
    float pitch;
    float pitch_min;
    float pitch_max;

   public:
    Camera();
    Camera(vec3 position);
    Camera(vec3 position, float yaw, float pitch);

    /// @brief Gets the position vector of this camera in the world
    /// @return Vec3 copy of position of camera
    vec3 get_position();

    /// @brief Sets the position of this mesh in the world
    /// @param position New world position vector to set
    void set_position(vec3 position);

    /// @brief Gets the yaw float value (along y axis)
    /// @return Yaw value
    float get_yaw();

    /// @brief Sets the yaw float value (along y axis)
    /// @param yaw New yaw value
    void set_yaw(float yaw);

    /// @brief Adjusts the yaw value, adding existing value
    /// @param yaw Amount to add to existing value
    void adj_yaw(float yaw);

    /// @brief Gets the pitch float value (along horizontal view axis)
    /// @return Pitch value
    float get_pitch();

    /// @brief Sets the pitch float value (along horizontal view axis)
    /// @param pitch New pitch value
    void set_pitch(float pitch);

    /// @brief Adjusts the pitch value, adding existing value
    /// @param pitch Amount to add to existing value
    void adj_pitch(float pitch);

    /// @brief Calculates and gets the forward facing vector for the camera's look direction
    /// @return A new normalized vec3 direction vector that camera is facing
    vec3 get_forward_dir();

    /// @brief Calculates a normalized forward facing vector only in the x/z space
    /// @return A new normalized vec3 with only x/z components
    vec3 get_horiz_forward_dir();

    /// @brief Calculates a normalized right facing vector only in the x/z space
    /// @return A new normalized vec3 with only x/z components
    vec3 get_horiz_right_dir();
};
