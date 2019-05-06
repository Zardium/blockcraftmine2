//
// Created by Zach on 5/1/2019.
//
#include "pch.hpp"
#include "BCM2.hpp"

#include <GLFW/glfw3.h>

namespace BlockCraftMine2
{

Window::Window(int width, int height)
{
   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
   glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
   glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
   glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

   m_window_handle = glfwCreateWindow(width, height, "BlockCraftMine 2", nullptr, nullptr);

   if (m_window_handle == nullptr)
   {
      std::cerr << "Failed to initialize OpenGL context";
      glfwTerminate();
      return;
   }

   // lock the mouse cursor within the window and hide it
   glfwSetInputMode(m_window_handle, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

   glfwMakeContextCurrent(m_window_handle);
}

Window::~Window()
{
   glfwDestroyWindow(m_window_handle);
}

Game::Game()
{
   glfwInit();

   m_window = std::make_unique<Window>();

   gladLoadGL();
}

Game::~Game()
{
   glfwTerminate();
}

Game& Game::operator()()
{
   while (!glfwWindowShouldClose(*m_window)) {
      if (glfwGetKey(*m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
         glfwSetWindowShouldClose(*m_window, true);

      // Background Fill Color
      glClearColor(0.5f, 0.8f, 1.0f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);



      // Flip Buffers and Draw
      glfwSwapBuffers(*m_window);
      glfwPollEvents();
   }
   return *this;
}

}