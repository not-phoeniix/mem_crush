#include "camera.h"

Camera::Camera()
  : position(vec3(0)),
    rotation(vec3(0)) { }

Camera::Camera(vec3 position)
  : position(position),
    rotation(vec3(0)) { }

Camera::Camera(vec3 position, vec3 rotation)
  : position(position),
    rotation(rotation) { }

vec3 Camera::get_position() { return position; }
void Camera::set_position(vec3 position) { this->position = position; }
vec3 Camera::get_rotation() { return rotation; }
void Camera::set_rotation(vec3 rotation) { this->rotation = rotation; }
