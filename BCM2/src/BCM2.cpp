//
// Created by Zach on 5/1/2019.
//
#include "pch.hpp"
#include "BCM2.hpp"

#include <GLFW/glfw3.h>

namespace BlockCraftMine2
{

Game::Game(int width, int height)
{
   glfwInit();
   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
   glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
   glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
   glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
   window_ = glfwCreateWindow(width, height, "BCM2", nullptr, nullptr);

   if (window_ == nullptr)
   {
      std::cerr << "Failed to initialize OpenGL context";
      glfwTerminate();
      return;
   }

   // lock the mouse cursor within the window and hide it
   glfwSetInputMode(window_, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

   glfwMakeContextCurrent(window_);
   gladLoadGL();
}

Game::~Game()
{
   glfwTerminate();
}

Game Game::operator()()
{
   while (!glfwWindowShouldClose(window_)) {
      if (glfwGetKey(window_, GLFW_KEY_ESCAPE) == GLFW_PRESS)
         glfwSetWindowShouldClose(window_, true);

      // Background Fill Color
      glClearColor(0.5f, 0.8f, 1.0f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);



      // Flip Buffers and Draw
      glfwSwapBuffers(window_);
      glfwPollEvents();
   }
   return *this;
}

}