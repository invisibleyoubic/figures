#pragma once

#include "figure.hpp"

namespace Figures
{

/// @brief Класс прямоугольника
class Rectangle final : public Figure
{
public:
    Rectangle(const float x, const float y, const bool isFixed);  
    virtual std::vector<float> points() override;
    virtual void setPoints(const float x, const float y) override;
};

}