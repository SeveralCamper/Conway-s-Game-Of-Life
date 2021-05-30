#ifndef SHOW_PIXEL_H_
#define SHOW_PIXEL_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <logic.h>

using namespace sf;

void ShowPixel(RenderWindow& window, CellStatus fieldArray[63][43]);

#endif
