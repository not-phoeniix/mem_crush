#include <iostream>
#include <vector>

#include "renderer.h"
#include "mesh.h"

Mesh test_mesh;

void update(float dt) {
}

void draw() {
    test_mesh.DrawWireframe();
}

int main(int argc, char* argv[]) {
    std::cout << "hiiiiii\n";

    test_mesh.LoadFromObj("res/models/cube.obj");
    test_mesh.set_scale(vec3(4));

    renderer_init(&argc, argv, update, draw);
    renderer_run();

    return 0;
}
