#include "Screen.h"
#include <SFML/Graphics.hpp>

LifeAlgorithm LAExmpl;

void CloseWindow(sf::RenderWindow& window)
{
    window.close();
}

void RandomGrid(sf::RenderWindow& window)
{
    LAExmpl.RandFillUniverse();
}

void CustomModeGrid(sf::RenderWindow& window)
{
}

void Screen(int width, int height, std::string name)
{
    LAExmpl.CreateUniverse();

    sf::RenderWindow window(sf::VideoMode(width, height), name);
    window.setVerticalSyncEnabled(true);

    /* Зоны */
    UserZone menuZone(
            5, 5, window.getSize().y - 10, window.getSize().x / 4, &window);
    menuZone.SetFillColor(sf::Color(0, 0, 0));

    UserZone gameZone(
            (window.getSize().x / 4) + 10,
            5,
            window.getSize().y - 100,
            ((window.getSize().x / 4) * 3) - 15,
            &window);
    gameZone.SetFillColor(sf::Color(0, 0, 0));

    UserZone statusZone(
            (window.getSize().x / 4) + 10,
            710,
            80,
            ((window.getSize().x / 4) * 3) - 15,
            &window);

    statusZone.SetFillColor(sf::Color(0, 0, 0));
    /* --- */

    /* кнопки */
    UserButton btnRandomMode("RANDOM MODE", 600, 20, 100, 100, &window);
    btnRandomMode.SetFillColor(sf::Color(0, 0, 0));
    btnRandomMode.ClickButton = RandomGrid;

    UserButton btnCustomMode("CUSTOM MODE", 600, 20, 100, 100, &window);
    btnCustomMode.SetFillColor(sf::Color(0, 0, 0));
    btnCustomMode.ClickButton = CustomModeGrid;

    UserButton btnClose("CLOSE", 600, 20, 100, 100, &window);
    btnClose.SetFillColor(sf::Color(0, 0, 0));
    btnClose.ClickButton = CloseWindow;
    /* --- */

    menuZone.PushButton(btnCustomMode);
    menuZone.PushButton(btnRandomMode);
    menuZone.PushButton(btnClose);

    sf::Clock clock;

    // программа работает сколь угодно долго,пока открыто наше окно
    while (window.isOpen()) {
        
        sf::Time time1 = clock.getElapsedTime();
        // проверяем все события окна,которые были запущены после последней
        // итерации цикла

        sf::Event event;

        while (window.pollEvent(event)) {
            // если произошло событие Закрытие,закрываем наше окно
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Установка цвета фона
        window.clear(sf::Color(255, 136, 0, 0));

        menuZone.DrawZone();
        statusZone.DrawZone();

        gameZone.DrawZone();

        std::cout << time1.asMilliseconds() << std::endl;

        ShowGrid(window);

        ShowPixel(window, LAExmpl.fieldArray);

        if (time1.asMilliseconds() > 100) {
            LAExmpl.Step();

            clock.restart();
        }


        // Отрисовка окна
        window.display();
    }
}