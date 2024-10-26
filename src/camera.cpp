#include "camera.h"

Camera::Camera()
  : position(vec3(0)),
    rotation(vec3(0)) {
    set_rotation(rotation);
}

Camera::Camera(vec3 position)
  : position(position),
    rotation(vec3(0)) {
    set_rotation(rotation);
}

Camera::Camera(vec3 position, vec3 rotation)
  : position(position),
    rotation(rotation) {
    set_rotation(rotation);
}

vec3 Camera::get_position() { return position; }
void Camera::set_position(vec3 position) { this->position = position; }
vec3 Camera::get_rotation() { return rotation; }
void Camera::set_rotation(vec3 rotation) {
    if (rotation == vec3(0)) {
        this->rotation = vec3(0, 0, -1);
    } else {
        normalize(rotation);
        this->rotation = rotation;
    }
}
