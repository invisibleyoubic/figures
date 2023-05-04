#include <cmath>

#include "../include/circle.hpp"

namespace Figures
{

Circle::Circle(const float x, const float y, const bool isFixed)
    : Figure(x, y, isFixed)
{}

std::vector<float> Circle::points()
{
    std::vector<float> result;

    if (!m_points.empty())
        return m_points;

    double radius = 0.1;
    for (int i = 0; i <= 300; i++)
    {
        double angle = 2 * 3.14 * i / 300;
        double x = cos(angle) * radius;
        double y = sin(angle) * radius;

        result.push_back(m_xCoord + x);
        result.push_back(m_yCoord + y);
    }

    return result;
}

void Circle::setPoints(const float x, const float y)
{
    m_points.clear();

    double radius = std::abs(m_xCoord - x);
    for (int i = 0; i <= 300; i++)
    {
        double angle = 2 * 3.14 * i / 300;
        double xCalc = cos(angle) * radius;
        double yCalc = sin(angle) * radius;

        m_points.push_back(m_xCoord + xCalc);
        m_points.push_back(m_yCoord + yCalc);
    }
}

}