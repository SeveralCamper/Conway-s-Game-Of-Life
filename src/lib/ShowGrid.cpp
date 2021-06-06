#include "ShowGrid.h"
#include <SFML/Graphics.hpp>

void ShowGrid(sf::RenderWindow& window)
{
    for (int i = 0; i < ARR_WIDTH; i++)
        for (int j = 0; j < ARR_HEIGHT; j++) {
            sf::RectangleShape rectangle(sf::Vector2f(10.f, 10.f));
            rectangle.setFillColor(BLACK_COLOR);
            rectangle.setOutlineThickness(.5f);
            rectangle.setOutlineColor(INDIGO_COLOR);
            rectangle.setPosition(360 + SIZE_CELLS * i, 11 + SIZE_CELLS * j);

            window.draw(rectangle);
        }
}