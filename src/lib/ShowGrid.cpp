#include "ShowGrid.h"

void ShowGrid(sf::RenderWindow& window)
{
    for (int i = 0; i < 65; i++)
        for (int j = 0; j < 40; j++) {
            sf::RectangleShape rectangle(sf::Vector2f(10.f, 10.f));
            rectangle.setFillColor(sf::Color(0, 0, 0));
            rectangle.setOutlineThickness(.5f);
            rectangle.setOutlineColor(sf::Color(75, 0, 130));
            rectangle.setPosition(353 + 16 * i, 5 + 16 * j);

            window.draw(rectangle);
        }
}