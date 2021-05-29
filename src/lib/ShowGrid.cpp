#include "ShowGrid.h"

void ShowGrid(RenderWindow& window)
{
    for (int i = 0; i < 65; i++)
        for (int j = 0; j < 40; j++) {
            RectangleShape rectangle(Vector2f(10.f, 10.f));
            rectangle.setFillColor(Color(0, 0, 0));
            rectangle.setOutlineThickness(.5f);
            rectangle.setOutlineColor(Color(75, 0, 130));
            rectangle.move(305 + 16 * i, 30 + 16 * j);

            window.draw(rectangle);
        }
}