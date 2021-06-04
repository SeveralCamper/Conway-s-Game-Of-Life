#include "Screen.h"
#include "Settings.h"
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
    /* Зона меню */
    sf::Vector2f menuZonePosition = sf::Vector2f(5, 5);
    sf::Vector2f menuZoneSize
            = sf::Vector2f(window.getSize().x * 0.25f, window.getSize().y - 10);

    UserZone menuZone(menuZonePosition, menuZoneSize, &window);
    menuZone.SetFillColor(BLACK_COLOR);

    /* Зона Игрового поля */
    sf::Vector2f gameZonePosition
            = sf::Vector2f((window.getSize().x * 0.25f) + 10, 5);
    sf::Vector2f gameZoneSize = sf::Vector2f(
            (window.getSize().x * 0.75f) - 15, (window.getSize().y * 0.8f) - 5);

    UserZone gameZone(gameZonePosition, gameZoneSize, &window);
    gameZone.SetFillColor(BLACK_COLOR);

    /* Зона статусной строки  */
    sf::Vector2f statusZonePosition = sf::Vector2f(
            (window.getSize().x * 0.25f) + 10,
            (window.getSize().y * 0.8f) + 10);
    sf::Vector2f statusZoneSize = sf::Vector2f(
            (window.getSize().x * 0.75f) - 15,
            (window.getSize().y * 0.2f) - 15);

    UserZone statusZone(statusZonePosition, statusZoneSize, &window);

    statusZone.SetFillColor(INDIGO_COLOR);
    /* --- */

    /* кнопки */
    UserButton btnRandomMode("RANDOM MODE", &window);
    btnRandomMode.SetFillColor(WHITE_COLOR);
    btnRandomMode.SetSize(sf::Vector2f(300, 60));
    btnRandomMode.ClickButton = RandomGrid;

    UserButton btnCustomMode("CUSTOM MODE", &window);
    btnCustomMode.SetFillColor(WHITE_COLOR);
    btnCustomMode.ClickButton = CustomModeGrid;

    UserButton btnClose("CLOSE", &window);
    btnClose.SetSize(sf::Vector2f(200, 60));
    btnClose.SetFillColor(WHITE_COLOR);
    btnClose.ClickButton = CloseWindow;
    /* --- */

    menuZone.AddButton(btnCustomMode);
    menuZone.AddButton(btnRandomMode);
    statusZone.AddButton(btnClose);

    sf::Clock clock;
    statusZone.ShowButtons();
    std::cout << statusZone.GetPosition().y << std::endl;
    std::cout << statusZone.collectionButtons[0].GetPosition().y << std::endl;

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

            /*  if (event.type == sf::Event::Resized) {

                 window.setSize(sf::Vector2u(event.size.height,
             event.size.width));
             } */
        }

        // Установка цвета фона
        window.clear(TANGERINE_COLOR);

        menuZone.DrawZone();
        gameZone.DrawZone();
        statusZone.DrawZone();

        ShowGrid(window);
        ShowPixel(window, LAExmpl.fieldArray);

        if (time1.asMilliseconds() > DELAY_MILLIS) {
            LAExmpl.Step();

            clock.restart();
        }

        // Отрисовка окна
        window.display();
    }
}