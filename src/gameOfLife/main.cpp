#include "logic.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <unistd.h>

using namespace sf;

void Erecta(RenderWindow& window, int fieldArray[40][40])
{
    window.clear(Color(0, 0, 0));

    for (int i = 0; i < 40; i++)
        for (int j = 0; j < 40; j++) {
            if (fieldArray[i][j] == 1) {
                RectangleShape rectangle(Vector2f(20.f, 20.f));
                rectangle.setFillColor(Color(255, 136, 0));
                rectangle.setOutlineThickness(7.f);
                rectangle.setOutlineColor(Color(0, 0, 0));
                rectangle.move(25 * i, 25 * j);
                window.draw(rectangle);
            }
        }
}

int main()
{
    LifeAlgorithm LAExmpl;
    LAExmpl.initLife();

    RenderWindow window(sf::VideoMode(1300, 1300), "LIFE");

    // программа работает сколь угодно долго,пока открыто наше окно
    while (window.isOpen()) {
        // проверяем все события окна,которые были запущены после последней
        // итерации цикла
        sf::Event event;
        while (window.pollEvent(event)) {
            // если произошло событие Закрытие,закрываем наше окно
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
             sf::Clock clock;
        float time = 0;
        while (time < 1) {
            time = clock.getElapsedTime().asSeconds();
            LAExmpl.RunLife();

            Erecta(window, LAExmpl.fieldArray);

            sf::sleep(sf::milliseconds(300));
            window.display();
        }
    }

    return 0;
}