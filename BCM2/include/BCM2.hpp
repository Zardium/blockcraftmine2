//
// Created by Zach on 5/1/2019.
//

#ifndef BCM2_BCM2_H
#define BCM2_BCM2_H

#include <GLFW/glfw3.h>
#include <memory>

namespace BlockCraftMine2
{

class Window
{
public:
   explicit Window(int width = default_width, int height = default_height);
   ~Window();
   operator GLFWwindow*() const { return m_window_handle; };
private:
   GLFWwindow* m_window_handle;
};

class Game
{
public:
    Game();

    ~Game();

    Game& operator()();

private:
    std::unique_ptr<Window> m_window;

};

}

#endif //BCM2_BCM2_H
