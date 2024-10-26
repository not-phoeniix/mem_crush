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

    vec3 position;
    vec3 rotation;
    vec3 scale;

   public:
    Mesh();
    ~Mesh();

    /// @brief Loads data from an OBJ file into this mesh object
    /// @param file_path Path to OBJ file to load
    void LoadFromObj(const char* file_path);

    /// @brief Draws the wireframe of this mesh, only the lines connecting vertices
    void DrawWireframe();

    /// @brief Gets the number of vertices in this mesh
    /// @return Unsigned integer of number of vertices
    unsigned int get_num_vertices();
    /// @brief Gets the number of faces in this mesh
    /// @return Unsigned integer of number of faces
    unsigned int get_num_faces();

    /// @brief Gets the position vector of this mesh in the world
    /// @return Vec3 copy of position of mesh
    vec3 get_position();

    /// @brief Sets the position of this mesh in the world
    /// @param position New world position vector to set
    void set_position(vec3 position);

    /// @brief Gets the rotation vector of this mesh in the world
    /// @return Vec3 copy of rotation of mesh
    vec3 get_rotation();

    /// @brief Sets the position vector of this mesh in the world
    /// @param rotation New rotation vector to set
    void set_rotation(vec3 rotation);

    /// @brief Gets the scale vector of this mesh in the world
    /// @return Vec3 copy of scale of mesh
    vec3 get_scale();

    /// @brief Sets the scale vector of this mesh in the world
    /// @param scale New scale vector to set
    void set_scale(vec3 scale);
};
