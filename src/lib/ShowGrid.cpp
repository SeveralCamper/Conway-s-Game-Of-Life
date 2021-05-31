#include "ShowGrid.h"
#include <SFML/Graphics.hpp>

void ShowGrid(sf::RenderWindow& window)
{
    for (int i = 0; i < 63; i++)
        for (int j = 0; j < 43; j++) {
            sf::RectangleShape rectangle(sf::Vector2f(10.f, 10.f));
            rectangle.setFillColor(sf::Color(0, 0, 0));
            rectangle.setOutlineThickness(.5f);
            rectangle.setOutlineColor(sf::Color(75, 0, 130));
            rectangle.setPosition(360 + 16 * i, 11 + 16 * j);

            window.draw(rectangle);
        }
}