//
// Created by Zach on 5/1/2019.
//

#ifndef BCM2_BCM2_H
#define BCM2_BCM2_H

#include <GLFW/glfw3.h>

namespace BlockCraftMine2
{

class Game
{
public:
    Game(int width, int height);

    ~Game();

    Game operator()();

private:
    GLFWwindow* window_;

};

}

#endif //BCM2_BCM2_H
