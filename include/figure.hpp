#pragma once

#include <vector>

namespace Figures
{

/// @brief Базовый класс фигуры
class Figure
{
public:
    Figure(const float x, const float y, const bool isFixed);

    /// @brief Возвращает список точек фигуры
    virtual std::vector<float> points() = 0;
    /// @brief Присваивает точки фигуре
    virtual void setPoints(const float X, const float Y) = 0;
    /// @brief Возвращает зафиксирована фигура или нет
    bool isFixed() const;
    /// @brief Делает фигуру зафиксированной
    void setFixed();
    /// @brief Возвращает координату X
    float xPos() const;
    /// @brief Возвращает координату Y 
    float yPos() const;

protected:
    float m_xCoord;                 ///< Координата X 
    float m_yCoord;                 ///< Координата Y
    bool m_isFixed;                 ///< Зафиксирована фигура или нет

    std::vector<float> m_points;    ///< Точки фигуры
};

}