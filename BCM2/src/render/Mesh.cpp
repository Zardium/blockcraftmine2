//
// Created by Zach on 5/4/2019.
//

#include "render/Mesh.hpp"

Mesh::Mesh(const std::vector<GLfloat>& vertices,
           const std::vector<GLfloat>& uv,
           const std::vector<GLuint>& indices)
:  m_index_count(indices.size())
{
   glGenVertexArrays(1, &m_VAO);
   bind();

   add_VBO(3, vertices);
   add_VBO(2, uv);
   add_EBO(indices);
}

Mesh::Mesh(const std::vector<GLfloat>& vertices,
           const std::vector<GLuint>& indices)
:  m_index_count(indices.size())
{
   glGenVertexArrays(1, &m_VAO);
   bind();

   add_VBO(3, vertices);
   add_EBO(indices);
}

Mesh::Mesh(Mesh&& other)
:  m_VAO(other.m_VAO),
   m_VBO_count(other.m_VBO_count),
   m_index_count(other.m_index_count),
   m_buffers(std::move(other.m_buffers))
{
   other.m_VAO = 0;
   other.m_VBO_count = 0;
   other.m_buffers.clear();
}

Mesh& Mesh::operator=(Mesh&& other)
{
   m_VAO = other.m_VAO;
   m_VBO_count = other.m_VBO_count;
   m_index_count = other.m_index_count;
   m_buffers = std::move(other.m_buffers);

   other.m_VAO = 0;
   other.m_VBO_count = 0;
   other.m_buffers.clear();

   return *this;
}

Mesh::~Mesh()
{
   glDeleteBuffers(m_buffers.size(), m_buffers.data());
   glDeleteVertexArrays(1, &m_VAO);
}

void Mesh::bind() const
{
   glBindVertexArray(m_VAO);
}

void Mesh::unbind() const
{
   glBindVertexArray(0);
}

GLuint Mesh::get_index_count() const
{
   return m_index_count;
}

void Mesh::add_VBO(int dimensions, const std::vector<GLfloat>& data)
{
   GLuint VBO;
   glGenBuffers(1, &VBO);
   glBindBuffer(GL_ARRAY_BUFFER, VBO);
   glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(data[0]),
                data.data(), GL_STATIC_DRAW);

   glVertexAttribPointer(m_VBO_count, dimensions, GL_FLOAT,
                              GL_FALSE, 0, nullptr);
   glEnableVertexAttribArray(m_VBO_count++);

   m_buffers.push_back(VBO);
}

Gluint Mesh::get_VAO() const
{
   return m_VAO;
}

void Mesh::add_EBO(const std::vector<GLuint>& indices)
{
   GLuint EBO;
   glGenBuffers(1, &EBO);
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
   glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(indices[0]),
                indices.data(), GL_STATIC_DRAW);

   m_buffers.push_back(EBO);
}