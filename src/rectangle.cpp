#include "../include/rectangle.hpp"

namespace Figures
{

Rectangle::Rectangle(const float x, const float y, const bool isFixed)
    : Figure(x, y, isFixed)
{}

std::vector<float> Rectangle::points()
{
    if (!m_points.empty())
        return m_points;

    return {m_xCoord,
            m_yCoord,
            m_xCoord,
            m_yCoord + 0.15f,
            m_xCoord + 0.15f,
            m_yCoord + 0.15f,
            m_xCoord + 0.15f,
            m_yCoord};
}

void Rectangle::setPoints(const float x, const float y)
{
    m_points.clear();
    
    m_points.push_back(m_xCoord);
    m_points.push_back(m_yCoord);

    m_points.push_back(m_xCoord);
    m_points.push_back(y);
    
    m_points.push_back(x);
    m_points.push_back(y);
    
    m_points.push_back(x);
    m_points.push_back(m_yCoord);
}

}