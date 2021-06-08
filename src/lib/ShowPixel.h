#ifndef SHOW_PIXEL_H_
#define SHOW_PIXEL_H_

#include <Logic.h>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Settings.h"

void ShowPixel(
        sf::RenderWindow& window, CellStatus fieldArray[ARR_WIDTH][ARR_HEIGHT]);

#endif
