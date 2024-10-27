#include <iostream>
#include <vector>

#include "window.h"
#include "mesh.h"
#include "input.h"

Mesh test_mesh;
Camera* cam;
vec2 prev_mouse_pos;

float move_speed = 30;
float cam_x_speed = 0.1f;
float cam_y_speed = 0.1f;

void update(float dt) {
    // ~~~ camera movement updating ~~~

    if (Input::IsDown(FORWARD)) {
        vec3 new_pos = cam->get_position();
        new_pos += cam->get_horiz_forward_dir() * move_speed * dt;
        cam->set_position(new_pos);
    }

    if (Input::IsDown(BACKWARD)) {
        vec3 new_pos = cam->get_position();
        new_pos -= cam->get_horiz_forward_dir() * move_speed * dt;
        cam->set_position(new_pos);
    }

    if (Input::IsDown(LEFT)) {
        vec3 new_pos = cam->get_position();
        new_pos -= cam->get_horiz_right_dir() * move_speed * dt;
        cam->set_position(new_pos);
    }

    if (Input::IsDown(RIGHT)) {
        vec3 new_pos = cam->get_position();
        new_pos += cam->get_horiz_right_dir() * move_speed * dt;
        cam->set_position(new_pos);
    }

    // ~~~ camera rotation updating ~~~
    vec2 diff = Input::get_mouse_pos() - prev_mouse_pos;
    cam->adj_yaw(diff.x * cam_x_speed * dt);
    cam->adj_pitch(-diff.y * cam_y_speed * dt);
    prev_mouse_pos = Input::get_mouse_pos();
}

void draw() {
    test_mesh.DrawWireframe();
}

int main(int argc, char* argv[]) {
    std::cout << "hiiiiii\n";

    test_mesh.LoadFromObj("res/models/cube.obj");
    test_mesh.set_scale(vec3(4));
    cam = new Camera(vec3(0, 0, 20));

    window_init(&argc, argv, update, draw, cam);
    window_run();

    return 0;
}
