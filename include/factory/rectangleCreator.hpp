#pragma once

#include "creator.hpp"

#include "../rectangle.hpp"


namespace Figures
{

/// @brief Создатель прямоугольников
class RectangleCreator : public Creator
{
public:
    RectangleCreator(const bool isFixed)
        : Creator(isFixed)
    {}


    /// @brief Возвращает фигуру 
    inline virtual Rectangle* getFigure(const float x, const float y) override
    {
        return new Rectangle(x, y, m_isFixedFigure);
    }
};

}
