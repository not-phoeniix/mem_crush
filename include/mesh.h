#pragma once

#include <glm/glm.hpp>

using namespace glm;

class Mesh {
   private:
    vec3* vertices;
    unsigned int num_vertices;
    uvec3* faces;
    unsigned int num_faces;
    bool is_loaded;

    void DrawFace(uvec3 face);

   public:
    Mesh();
    ~Mesh();

    ///@brief Loads data from an OBJ file into this mesh object
    ///@param file_path Path to OBJ file to load
    void LoadFromObj(const char* file_path);

    ///@brief Draws the wireframe of this mesh, only the lines connecting vertices
    void DrawWireframe();

    /// @brief Gets the number of vertices in this mesh
    /// @return Unsigned integer of number of vertices
    unsigned int get_num_vertices();
    /// @brief Gets the number of faces in this mesh
    /// @return Unsigned integer of number of faces
    unsigned int get_num_faces();
};
