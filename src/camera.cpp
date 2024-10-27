#include "camera.h"

Camera::Camera()
  : Camera::Camera(vec3(0)) { }

Camera::Camera(vec3 position)
  : Camera::Camera(position, M_PI * 3.0f / 2.0f, 0) { }

Camera::Camera(vec3 position, float yaw, float pitch)
  : position(position),
    yaw(yaw),
    pitch(pitch),
    pitch_min(-M_PI_4),
    pitch_max(M_PI_4) { }

vec3 Camera::get_position() { return position; }
void Camera::set_position(vec3 position) { this->position = position; }

float Camera::get_yaw() { return yaw; }
void Camera::set_yaw(float yaw) { this->yaw = yaw; }
void Camera::adj_yaw(float yaw) { this->yaw += yaw; }

float Camera::get_pitch() { return pitch; }
void Camera::set_pitch(float pitch) {
    this->pitch = pitch;
    this->pitch = clamp(this->pitch, pitch_min, pitch_max);
}
void Camera::adj_pitch(float pitch) {
    this->pitch += pitch;
    this->pitch = clamp(this->pitch, pitch_min, pitch_max);
}

vec3 Camera::get_forward_dir() {
    // vertical direction (y) only impacted by pitch,
    //   z and x are combo of pitch and yaw
    vec3 dir(
        cos(yaw) * cos(pitch),
        sin(pitch),
        sin(yaw) * cos(pitch)
    );

    return dir;
}
