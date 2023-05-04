#include "../include/triangle.hpp"

namespace Figures
{
Triangle::Triangle(const float x, const float y, const bool isFixed) 
    : Figure(x, y, isFixed)
{}

std::vector<float> Triangle::points()
{
    if (!m_points.empty())
        return m_points;
    
    return {m_xCoord,
            m_yCoord,
            m_xCoord + 0.2f,
            m_yCoord,
            m_xCoord,
            m_yCoord + 0.2f};
}

void Triangle::setPoints(const float x, const float y)
{
    m_points.clear();

    m_points.push_back(m_xCoord);
    m_points.push_back(m_yCoord);

    m_points.push_back(x);
    m_points.push_back(m_yCoord);
    
    m_points.push_back(m_xCoord);
    m_points.push_back(y);
}

}
