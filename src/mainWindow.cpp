#include <iostream>
#include <vector>
#include <cmath>

#include "../include/triangle.hpp"
#include "../include/rectangle.hpp"
#include "../include/helper.hpp"
#include "../include/circle.hpp"
#include "../include/mainWindow.hpp"

#include "../include/factory/creator.hpp"
#include "../include/factory/rectangleCreator.hpp"
#include "../include/factory/triangleCreator.hpp"
#include "../include/factory/circleCreator.hpp"

namespace
{
    static int radioButtonTypeOfFigureFalseValue = 0;
    static int radioButtonTypeOfGenerationFalseValue = 0;
}

namespace Figures
{

enum FigureType
{
    triangle = 0,
    rectangle,
    circle,
};

MainWindow::MainWindow()
    : m_backgroundColor(0.45f, 0.55f, 0.60f, 1.00f)
    , m_creator(new TriangleCreator(true))
    , m_window(NULL)
    , m_prevMouseLeftButtonState(0)
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    if (!createUI())
        return;
}

MainWindow::~MainWindow()
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void MainWindow::run()
{
    bool isFixedFigure = true;
    FigureType figureType = FigureType::triangle;
    
    while (!glfwWindowShouldClose(m_window))
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        {
            ImGui::Begin("Select type of figure");

            if (ImGui::RadioButton("Triangle", &radioButtonTypeOfFigureFalseValue, 0))
                figureType = FigureType::triangle;
            if (ImGui::RadioButton("Rectangle", &radioButtonTypeOfFigureFalseValue, 1))
                figureType = FigureType::rectangle;
            if (ImGui::RadioButton("Circle", &radioButtonTypeOfFigureFalseValue, 2))
                figureType = FigureType::circle;

            ImGui::SeparatorText("Type of generation");
            
            if (ImGui::RadioButton("Fixed size", &radioButtonTypeOfGenerationFalseValue, 0))
                isFixedFigure = true;
            if (ImGui::RadioButton("Manual size", &radioButtonTypeOfGenerationFalseValue, 1))
                isFixedFigure = false;

            switch (figureType)
            {
            case FigureType::triangle:
                m_creator = new TriangleCreator(isFixedFigure);
            break;
            case FigureType::rectangle:
                m_creator = new RectangleCreator(isFixedFigure);
            break;
            case FigureType::circle:
                m_creator = new CircleCreator(isFixedFigure);
            break;
            }

            ImGui::End();
        }

        glClearColor(m_backgroundColor.x * m_backgroundColor.w, m_backgroundColor.y * m_backgroundColor.w, m_backgroundColor.z * m_backgroundColor.w, m_backgroundColor.w);
        glClear(GL_COLOR_BUFFER_BIT);

        double xCursorPos;
        double yCursorPos;
        glfwGetCursorPos(m_window, &xCursorPos, &yCursorPos);
        m_xCursorPos = Helpers::Helper::instance()->normalizeCoordinates(xCursorPos, Helpers::Helper::Axis::X);
        m_yCursorPos = Helpers::Helper::instance()->normalizeCoordinates(yCursorPos, Helpers::Helper::Axis::Y);

        int mouseLeftButtonState = glfwGetMouseButton(m_window, GLFW_MOUSE_BUTTON_LEFT);
        if (GLFW_PRESS == mouseLeftButtonState)
        {
            if (!isFixedFigure)
            {
                if (!m_figures.empty())
                {
                    if (m_figures.back()->isFixed())
                        addFigureToBuffer();

                    addFigurePoinst();   
                }
                else
                {
                    addFigureToBuffer();
                    addFigurePoinst();
                }
            }
            else
                addFigureToBuffer();

            m_prevMouseLeftButtonState = 1;
        }

        if (GLFW_RELEASE == mouseLeftButtonState && m_prevMouseLeftButtonState == GLFW_PRESS)
        {
            if (!m_figures.empty())
            {
                Figure* figure = m_figures.back();
                if (!figure->isFixed())
                    figure->setFixed();
            }

            m_prevMouseLeftButtonState = 0;
        }

        if (GLFW_PRESS == glfwGetMouseButton(m_window, GLFW_MOUSE_BUTTON_RIGHT))
        {
            if (!m_figures.empty())
                m_figures.erase(m_figures.end() - 1);
        }

        draw();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
 
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
}

bool MainWindow::createUI()
{
    if (!glfwInit())
    {
        std::cout << "init error" << std::endl;
        return false;
    }
 
    const std::pair<int, int> screenSize = Helpers::Helper::instance()->getResolution();

    m_window = glfwCreateWindow(screenSize.first / 2, screenSize.second, "Figures", NULL, NULL);
    if (NULL == m_window)
    {
        std::cout << "creating window error" << std::endl;
        return false;
    }

    glfwMakeContextCurrent(m_window);
    glfwSwapInterval(1);
 
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
 
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(m_window, true);
    ImGui_ImplOpenGL3_Init("#version 130");
 
    gladLoadGL();
    return true;
}

void MainWindow::addFigureToBuffer()
{
    m_figures.push_back(m_creator->getFigure(m_xCursorPos, m_yCursorPos));
}

void MainWindow::addFigurePoinst()
{
    Figure* figure = m_figures.back();
    figure->setPoints(m_xCursorPos, m_yCursorPos);
}

void MainWindow::draw()
{
    if (m_figures.empty())
        return;
        
    for (Figure* figure : m_figures)
    {
        const std::vector<float> vertices = figure->points();
        
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_POLYGON);
        for (auto index = vertices.cbegin(); index != vertices.cend(); index+=2)
        {
            glVertex2f(*index, *(index+1));
        }
        glEnd();

        glColor3f(0.9f, 0.2f, 0.6f);
        glBegin(GL_LINE_LOOP);
        for (auto index = vertices.cbegin(); index != vertices.cend(); index+=2)
        {
            glVertex2f(*index, *(index+1));
        }
        glEnd();
    }
}

}
