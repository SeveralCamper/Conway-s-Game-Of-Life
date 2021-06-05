#include "ShowPixel.h"

void ShowPixel(
        sf::RenderWindow& window, CellStatus fieldArray[ARR_WIDTH][ARR_HEIGHT])
{
    for (int i = 0; i < ARR_WIDTH; i++)
        for (int j = 0; j < ARR_HEIGHT; j++) {
            if (fieldArray[i][j] != CellStatus::DIE) {
                sf::RectangleShape rectangle(sf::Vector2f(10.f, 10.f));
                rectangle.setFillColor(sf::Color(255, 136, 0));
                rectangle.setOutlineThickness(.5f);
                rectangle.setOutlineColor(sf::Color(255, 165, 0));
                rectangle.move(360 + 16 * i, 11 + 16 * j);
                window.draw(rectangle);
            }

            if (fieldArray[i][j] == CellStatus::BORN) {
                sf::RectangleShape rectangle(sf::Vector2f(10.f, 10.f));
                rectangle.setFillColor(sf::Color(50, 205, 50));
                rectangle.setOutlineThickness(.5f);
                rectangle.setOutlineColor(sf::Color(0, 255, 0));
                rectangle.move(360 + 16 * i, 11 + 16 * j);
                window.draw(rectangle);
            }
        }
}