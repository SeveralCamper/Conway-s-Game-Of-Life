#include "DrawScrean.h"

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
