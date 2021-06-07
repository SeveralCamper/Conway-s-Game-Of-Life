#include "ShowPixel.h"

void ShowPixel(
        sf::RenderWindow& window, CellStatus fieldArray[ARR_WIDTH][ARR_HEIGHT])
{
    for (int i = 0; i < ARR_WIDTH; i++)
        for (int j = 0; j < ARR_HEIGHT; j++) {
            if (fieldArray[i][j] != CellStatus::DIE) {
                sf::RectangleShape rectangle(sf::Vector2f(10.f, 10.f));
                rectangle.setFillColor(TANGERINE_COLOR);
                rectangle.setOutlineThickness(.5f);
                rectangle.setOutlineColor(ORANGE_COLOR);
                rectangle.move(360 + SIZE_CELLS * i, 11 + SIZE_CELLS * j);
                window.draw(rectangle);
            }

            if (fieldArray[i][j] == CellStatus::BORN) {
                sf::RectangleShape rectangle(sf::Vector2f(10.f, 10.f));
                rectangle.setFillColor(LIME_GREEN_COLOR);
                rectangle.setOutlineThickness(.5f);
                rectangle.setOutlineColor(LIME_COLOR);
                rectangle.move(360 + SIZE_CELLS * i, 11 + SIZE_CELLS * j);
                window.draw(rectangle);
            }
        }
}