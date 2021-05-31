
#include <SFML/Graphics.hpp>
#include <Screen.h>
#include <ShowGrid.h>
#include <ShowPixel.h>
#include <UserButton.h>
#include <iostream>
#include <logic.h>

int main()
{
    int screenWidth = 1374;
    int screenHeight = 795;
    std::string nameWindow = "Life";

    // Отрисовка окна программы
    Screen(screenWidth, screenHeight, nameWindow);

    return 0;
}
