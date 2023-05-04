#pragma once

#include "../figure.hpp"

namespace Figures
{

/// @brief Базовый класс создатель фигур
class Creator
{
public:
    Creator(const bool isFixed)
        : m_isFixedFigure(isFixed)
    {}
    virtual ~Creator() = default;

    /// @brief Возвращает созданную фигуру
    inline virtual Figure* getFigure(const float x, const float y) = 0;

protected:
    bool m_isFixedFigure;
};

}
