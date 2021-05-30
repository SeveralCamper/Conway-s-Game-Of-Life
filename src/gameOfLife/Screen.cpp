#include "Screen.h"

void CloseWindow(sf::RenderWindow& window)
{
    window.close();
}

// Создание зоны меню
void CreateMenuZone(sf::RenderWindow& window)
{
    sf::RectangleShape menuZone;
    menuZone.setSize(sf::Vector2f(
            (window.getSize().x / 3) - 15, window.getSize().y - 10));
    menuZone.setPosition(sf::Vector2f(5, 5));
    window.draw(menuZone);
}

// Создание игровой зоны
void CreateGameZone(sf::RenderWindow& window)
{
    sf::RectangleShape gameZone;
    gameZone.setSize(sf::Vector2f(
            ((window.getSize().x / 3) * 2) - 20, window.getSize().y - 105));

    gameZone.setPosition(sf::Vector2f((window.getSize().x / 3) + 15, 5));
    window.draw(gameZone);
}

// Создание зоны отображения статуса игры
void CreateStatusZone(sf::RenderWindow& window)
{
    sf::RectangleShape statusZone;
    statusZone.setSize(sf::Vector2f(((window.getSize().x / 3) * 2) - 20, 70));

    statusZone.setPosition(sf::Vector2f(
            (window.getSize().x / 3) + 15, window.getSize().y - 75));

    window.draw(statusZone);
}

void Screen(int width, int height, std::string name)
{
    sf::RenderWindow window(sf::VideoMode(width, height), name);
    window.setVerticalSyncEnabled(true);

    /////////////////////////////

    UserZone menuZone(5, 5, window.getSize().y - 10, window.getSize().x / 4, &window);
    /////////////////////////////

    ///////////////////////////////
    UserButton btn("CLOSE", 600, 20, 100, 100, &window);
    btn.SetFillColor(sf::Color(34, 123, 34));
    btn.ClickButton = CloseWindow;
    /////////////////////////

    menuZone.PushButton(btn);
    menuZone.PushButton(btn);
    menuZone.PushButton(btn);
    menuZone.PushButton(btn);

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

        /*         CreateMenuZone(window);
                CreateGameZone(window);
                CreateStatusZone(window); */

        menuZone.DrawZone();

        // Отрисовка окна
        window.display();
    }
}