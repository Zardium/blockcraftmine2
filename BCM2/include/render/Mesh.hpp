//
// Created by Zach on 5/4/2019.
//

#ifndef BCM2_MESH_HPP
#define BCM2_MESH_HPP

#include "pch.hpp"
#include <vector>
#include "phys/AABB.hpp"

class Mesh
{
public:
   Mesh() = default;
   Mesh(const std::vector<GLfloat>& vertices,
         const std::vector<GLfloat>& uv,
         const std::vector<GLuint>& indices);
   Mesh(const std::vector<GLfloat>& vertices,
        const std::vector<GLuint>& indices);
   ~Mesh();

   // Disallow copying meshes
   Mesh(const Mesh& other) = delete;
   Mesh& operator=(const Model& other) = delete;

   // Allow move semantics
   Mesh(Mesh&& other);
   Mesh& operator=(Mesh&& other);

   void add_VBO(int dimensions, const std::vector<GLfloat>& data);

   void bind() const;
   void unbind() const;

   GLuint get_VAO() const;
   GLuint get_index_count() const;
private:

   void add_EBO(const std::vector<GLuint>& indices);

   GLuint m_VAO;
   GLuint m_VBO_count;
   GLuint m_index_count;
   std::vector<GLuint> m_buffers;
};


#endif //BCM2_MESH_HPP
