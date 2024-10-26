#pragma once

#include <GL/freeglut.h>
#include <glm/glm.hpp>

using namespace glm;

class Polygon {
   private:
    vec2* vertices;
    unsigned int num_vertices;
    vec3 color;

   public:
    Polygon(vec2* vertices_array, unsigned int num_vertices, vec3 color);
    void Draw();
};
