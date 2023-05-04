#pragma once

#include <vector>

#include "lib/imgui.h"
#include "lib/imgui_impl_glfw.h"
#include "lib/imgui_impl_opengl3.h"

#include "lib/glad.h"
#include "lib/glfw3.h"

#include "factory/creator.hpp"
#include "figure.hpp"

namespace Figures
{

/// @brief Окно программы
class MainWindow
{
public:
    MainWindow();
    ~MainWindow();

    /// @brief Запускает главный цикл программы
    void run();

private:
    /// @brief Создает окно программы и интерфейс для выбора типа фигуры и типа генерации
    bool createUI();
    /// @brief Добавляет фигуру в буфер
    void addFigureToBuffer();
    /// @brief Изменяет границы фигуры, пока зажата кнопка мышки
    void addFigurePoinst();
    /// @brief Рисует фигуру
    void draw();

private:
    ImVec4 m_backgroundColor;       ///< Цвет фона

    float m_yCursorPos;             ///< Позиция курсора по Y
    float m_xCursorPos;             ///< Позиция курсора по X

    std::vector<Figure*> m_figures; ///< Буфер со всеми нарисованными фигурами
    Creator* m_creator;             ///< Объект, который создает выбранную фигуру

    GLFWwindow* m_window;           ///< Окно программы

    int m_prevMouseLeftButtonState; ///< Предыдущее состоянии мыши
};

}
