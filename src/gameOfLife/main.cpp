
#include "DrawScrean.h"
#include "ShowGrid.h"
#include "ShowPixel.h"
#include "logic.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int main()
{
    LifeAlgorithm LAExmpl;
    LAExmpl.initLife();

    DrawScrean(LAExmpl);
    return 0;
}
