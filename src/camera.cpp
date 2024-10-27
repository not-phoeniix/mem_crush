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
void Camera::set_yaw(float yaw) {
    this->yaw = yaw;
    if (this->yaw < 0) this->yaw = 2 * M_PI;
    if (this->yaw > 2 * M_PI) this->yaw = 0;
}
void Camera::adj_yaw(float yaw) {
    this->yaw += yaw;
    if (this->yaw < 0) this->yaw = 2 * M_PI;
    if (this->yaw > 2 * M_PI) this->yaw = 0;
}

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
    return vec3(
        cos(yaw) * cos(pitch),
        sin(pitch),
        sin(yaw) * cos(pitch)
    );
}

vec3 Camera::get_horiz_forward_dir() {
    // get the forward direction without a y component,
    //   only in x/z space with yaw
    return vec3(
        cos(yaw),
        0,
        sin(yaw)
    );
}

vec3 Camera::get_horiz_right_dir() {
    // get the right direction without a y component,
    //   only in x/z space with yaw
    return vec3(
        cos(yaw + M_PI_2),
        0,
        sin(yaw + M_PI_2)
    );
}
