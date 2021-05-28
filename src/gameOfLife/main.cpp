#include "logic.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

void ShowGrid(RenderWindow& window)
{
    window.clear(Color(0, 0, 0));

    for (int i = 0; i < 55; i++)
        for (int j = 0; j < 55; j++) {
            RectangleShape rectangle(Vector2f(10.f, 10.f));
            rectangle.setFillColor(Color(0, 0, 0));
            rectangle.setOutlineThickness(.5f);
            rectangle.setOutlineColor(Color(75, 0, 130));
            rectangle.move(16 * i, 16 * j);
            window.draw(rectangle);
        }
}

void ShowPixel(RenderWindow& window, bool fieldArray[55][55])
{
    // window.clear(Color(0, 0, 0));

    for (int i = 0; i < 55; i++)
        for (int j = 0; j < 55; j++) {
            if (fieldArray[i][j] == 1) {
                RectangleShape rectangle(Vector2f(10.f, 10.f));
                rectangle.setFillColor(Color(255, 136, 0));
                rectangle.setOutlineThickness(.5f);
                rectangle.setOutlineColor(Color(255, 165, 0));
                rectangle.move(16 * i, 16 * j);
                window.draw(rectangle);
            }
        }
}

void DrawScrean(LifeAlgorithm LAExmpl)
{
    RenderWindow window(sf::VideoMode(880, 880), "Conway's Game Of Life");

    // программа работает сколь угодно долго,пока открыто наше окно
    while (window.isOpen()) {
        // проверяем все события окна,которые были запущены после последней
        // итерации цикла
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        sf::Clock clock;
        float time = 0;
        while (time < 1) {
            time = clock.getElapsedTime().asSeconds();
            LAExmpl.RunLife();

            ShowGrid(window);

            ShowPixel(window, LAExmpl.fieldArray);

            sf::sleep(sf::milliseconds(300));
            window.display();
        }
    }
}

int main()
{
    LifeAlgorithm LAExmpl;
    LAExmpl.initLife();

    DrawScrean(LAExmpl);
    return 0;
}
