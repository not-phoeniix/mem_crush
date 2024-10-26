#include "polygon.h"

Polygon::Polygon(vec2* vertices_array, unsigned int num_vertices, vec3 color)
  : vertices(vertices_array),
    num_vertices(num_vertices),
    color(color) { }

void Polygon::Draw() {
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POLYGON);

    for (int i = 0; i < num_vertices; i++) {
        glVertex2f(vertices[i].x, vertices[i].y);
    }

    glEnd();
}
