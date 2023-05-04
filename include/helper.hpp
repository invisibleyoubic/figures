#pragma once

#include <utility>

namespace Helpers
{

class Helper
{
public:
    enum Axis
    {
        X = 0,
        Y,
    };

public:
    static Helper* instance();

    std::pair<int, int> getResolution();
    float normalizeCoordinates(double coodinate, Axis axis);

private:
    Helper();
};

}