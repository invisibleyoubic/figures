#include "include/mainWindow.hpp"

int main()
{
    Figures::MainWindow* mainWIndow = new Figures::MainWindow();
    mainWIndow->run();
    delete(mainWIndow);

    return 0;
}