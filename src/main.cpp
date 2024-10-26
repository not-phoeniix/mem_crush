#include <iostream>
#include <vector>

#include "window.h"
#include "mesh.h"
#include "input.h"

Mesh test_mesh;
Camera* cam;

float cam_speed = 30;

void update(float dt) {
    if (Input::IsDown(FORWARD)) {
        vec3 new_pos = cam->get_position();
        new_pos.y += cam_speed * dt;
        cam->set_position(new_pos);
    }

    if (Input::IsDown(BACKWARD)) {
        vec3 new_pos = cam->get_position();
        new_pos.y -= cam_speed * dt;
        cam->set_position(new_pos);
    }

    if (Input::IsDown(LEFT)) {
        vec3 new_pos = cam->get_position();
        new_pos.x -= cam_speed * dt;
        cam->set_position(new_pos);
    }

    if (Input::IsDown(RIGHT)) {
        vec3 new_pos = cam->get_position();
        new_pos.x += cam_speed * dt;
        cam->set_position(new_pos);
    }
}

void draw() {
    test_mesh.DrawWireframe();
}

int main(int argc, char* argv[]) {
    std::cout << "hiiiiii\n";

    test_mesh.LoadFromObj("res/models/cube.obj");
    test_mesh.set_scale(vec3(4));
    cam = new Camera(
        vec3(0, 0, 20),
        vec3(0, 0, -1)
    );

    window_init(&argc, argv, update, draw, cam);
    window_run();

    return 0;
}
