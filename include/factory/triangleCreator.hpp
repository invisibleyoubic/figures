#pragma once

#include "creator.hpp"

#include "../triangle.hpp"

namespace Figures
{

/// @brief Класс создатель треугольников
class TriangleCreator : public Creator
{
public:
    TriangleCreator(const bool isFixed)
        : Creator(isFixed)
    {}

    inline virtual Triangle* getFigure(const float x, const float y) override
    {
        return new Triangle(x, y, m_isFixedFigure);
    }
};

}
