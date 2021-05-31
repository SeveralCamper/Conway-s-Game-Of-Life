#ifndef SREEN_H_
#define SREEN_H_

#include <iostream>
#include <SFML/Graphics.hpp>

#include "ShowGrid.h"
#include "ShowPixel.h"
#include "UserButton.h"
#include "UserZone.h"
#include "Screen.h"
#include "logic.h"

void CloseWindow(sf::RenderWindow& window);

void Screen(int width, int height, std::string name);

#endif