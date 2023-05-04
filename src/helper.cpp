#include "../include/lib/glfw3.h"

#include "../include/helper.hpp"

namespace Helpers
{

Helper* Helper::instance()
{
    static Helper* instance = new Helper();

    return instance;
}

Helper::Helper()
{}

std::pair<int, int> Helper::getResolution()
{
    const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    std::pair<int, int> result { mode->width, mode->height };
    return result;
}

float Helper::normalizeCoordinates(double coordinate, Axis axis)
{
    if (coordinate == 500)
        return 0.0f;

    switch (axis)
    {
    case Axis::X:
    if (coordinate < 500)
        return  - (1 - (coordinate / 500));

    if (coordinate > 500)
        return (coordinate - 500) / 500;
    break;
    
    case Axis::Y:
    if (coordinate < 500)
        return  1 - (coordinate / 500);

    if (coordinate > 500)
        return - (coordinate - 500) / 500;

    break;
    default:
        break;
    }

    return 0;
}

}