#include "Screen.h"

void CloseWindow(sf::RenderWindow& window)
{
    window.close();
}

void Screen(int width, int height, std::string name)
{
    sf::RenderWindow window(sf::VideoMode(width, height), name);
    window.setVerticalSyncEnabled(true);

    UserButton btn("CLOSE", 600, 20, 100, 70, &window);
    btn.SetFillColor(sf::Color(34, 123, 34));
    btn.ClickButton = CloseWindow;

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

        // Установка цвета фона
        window.clear(sf::Color(0, 220, 100, 0));

        btn.DrawButton();
        btn.IsClickButton(sf::Mouse::getPosition(window));

        // Отрисовка окна
        window.display();
    }
}