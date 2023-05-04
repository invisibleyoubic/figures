#include "../include/figure.hpp"

namespace Figures
{

Figure::Figure(const float x, const float y, const bool isFixed)
    : m_xCoord(x)
    , m_yCoord(y)
    , m_isFixed(isFixed)
{}

bool Figure::isFixed() const
{
    return m_isFixed;
}

void Figure::setFixed()
{
    m_isFixed = true;
}

float Figure::xPos() const
{
    return m_xCoord;
}

float Figure::yPos() const
{
    return m_yCoord;
}

}