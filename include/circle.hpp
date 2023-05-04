#pragma once

#include "figure.hpp"

namespace Figures
{

/// @brief Класс круга
class Circle final : public Figure
{
public:
    Circle(const float x, const float y, const bool isFixed = true);
    virtual std::vector<float> points() override;
    virtual void setPoints(const float x, const float y) override;
};

}
