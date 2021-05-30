
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Screen.h"
#include "UserButton.h"
#include "ShowGrid.h"
#include "ShowPixel.h"
#include "logic.h"

int main()
{
    LifeAlgorithm LAExmpl;
    LAExmpl.initLife();

    // Отрисовка окна программы
    Screen(1374, 795, "Life");

    return 0;
}
