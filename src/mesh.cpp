#include "mesh.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <GL/freeglut.h>

using namespace std;

Mesh::Mesh() {
    vertices = nullptr;
    num_vertices = 0;
    faces = nullptr;
    num_faces = 0;
    is_loaded = false;
    position = vec3(0, 0, 0);
    rotation = vec3(0, 0, 0);
    scale = vec3(1, 1, 1);
}

Mesh::~Mesh() {
    if (is_loaded) {
        delete[] vertices;
        delete[] faces;
    }
}

void Mesh::LoadFromObj(const char* file_path) {
    cout << "loading obj file from path \"" << file_path << "\"...\n";

    if (is_loaded) {
        cout << "ERROR: mesh already loaded! cannot load new OBJ file!";
        return;
    }

    vector<vec3> tmp_vertices;
    vector<uvec3> tmp_faces;
    ifstream file(file_path);

    if (!file.is_open()) {
        cout << "ERROR: filepath could not be opened in stream!\n";
        return;
    }

    // get all lines from input file stream and iterate across
    string line;
    while (getline(file, line)) {
        // skip lines that are empty or are comments
        if (line == "" || line == "\n" || line[0] == '#') {
            continue;
        }

        // create a string stream from each line
        istringstream iss(line);

        char type;
        iss >> type;

        // first character in each line determines what that line's data contains
        switch (type) {
            // vertex reading
            case 'v':
                vec3 vert;
                iss >> vert.x;
                iss >> vert.y;
                iss >> vert.z;
                tmp_vertices.push_back(vert);
                break;

            // face reading
            case 'f':
                uvec3 face;
                iss >> face.x;
                iss >> face.y;
                iss >> face.z;

                // decrease index by 1 since obj vertex indices start at 1 and not 0
                face -= uvec3(1);

                tmp_faces.push_back(face);
                break;

            // quad reading
            case 'q':
                uvec4 quad;
                iss >> quad.x;
                iss >> quad.y;
                iss >> quad.z;
                iss >> quad.w;

                // decrease index by 1 since obj vertex indices start at 1 and not 0
                quad -= uvec4(1);

                // create two triangles from the quad
                uvec3 tri_one(quad.x, quad.y, quad.z);
                uvec3 tri_two(quad.x, quad.w, quad.z);

                tmp_faces.push_back(tri_one);
                tmp_faces.push_back(tri_two);
                break;
        }
    }

    file.close();

    num_vertices = tmp_vertices.size();
    vertices = new vec3[num_vertices];
    for (int i = 0; i < num_vertices; i++) {
        vertices[i] = tmp_vertices[i];
    }

    num_faces = tmp_faces.size();
    faces = new uvec3[num_faces];
    for (int i = 0; i < num_faces; i++) {
        faces[i] = tmp_faces[i];
    }

    is_loaded = true;
    cout << "obj file at path \"" << file_path << "\" loaded :D!\n";
}

void Mesh::DrawWireframe() {
    // don't draw mesh if there's nothing to draw in the first place
    if (num_vertices == 0 || num_faces == 0) {
        return;
    }

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(scale.x, scale.y, scale.z);
    glTranslatef(position.x, position.y, position.z);
    // glRotatef(angle?, rotation.x, rotation.y, rotation.z);

    float color_step = 1.0f / num_faces;
    float color = 0;

    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < num_faces; i++) {
        glColor3f(color, 1 - color, 1);

        uvec3 face = faces[i];

        vec3 point_one = vertices[face.x];
        glVertex3f(point_one.x, point_one.y, point_one.z);

        vec3 point_two = vertices[face.y];
        glVertex3f(point_two.x, point_two.y, point_two.z);

        vec3 point_three = vertices[face.z];
        glVertex3f(point_three.x, point_three.y, point_three.z);

        color += color_step;
    }
    glEnd();

    glPopMatrix();
}

unsigned int Mesh::get_num_vertices() {
    return num_vertices;
}

unsigned int Mesh::get_num_faces() {
    return num_faces;
}

vec3 Mesh::get_position() { return position; }
void Mesh::set_position(vec3 position) { this->position = position; }

vec3 Mesh::get_rotation() { return rotation; }
void Mesh::set_rotation(vec3 rotation) { this->rotation = rotation; }

vec3 Mesh::get_scale() { return scale; }
void Mesh::set_scale(vec3 scale) { this->scale = scale; }
