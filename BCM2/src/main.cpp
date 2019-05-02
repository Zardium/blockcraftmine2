// Local Headers
#include "pch.hpp"
#include "BCM2.hpp"

// System Headers
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Standard Headers
#include <cstdio>
#include <cstdlib>
#include <thread>

int main(int argc, char * argv[])
{
   BlockCraftMine2::Game main_game(default_width, default_height);
   std::thread main_game_thread(main_game());
   return EXIT_SUCCESS;
}
