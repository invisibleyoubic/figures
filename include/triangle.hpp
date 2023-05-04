#pragma once

#include "figure.hpp"

namespace Figures
{

/// @brief Класс треугольника
class Triangle final : public Figure
{
public:
    Triangle(const float x, const float y, const bool isFixed);
    virtual std::vector<float> points() override;
    virtual void setPoints(const float x, const float y) override;
};

}