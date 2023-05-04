#pragma once

#include "creator.hpp"

#include "../circle.hpp"


namespace Figures
{

/// @brief Класс создатель кругов
class CircleCreator : public Creator
{
public:
    CircleCreator(const bool isFixed)
        : Creator(isFixed)
    {}

    inline virtual Circle* getFigure(const float x, const float y) override
    {
        return new Circle(x, y, m_isFixedFigure);
    }
};

}
