#include "Screen.h"
#include "Settings.h"
#include "models.h"

#include <SFML/Graphics.hpp>

LifeAlgorithm LAExmpl;

void CloseWindow(sf::RenderWindow& window)
{
    window.close();
}

void RandomGrid(sf::RenderWindow& window)
{
    LAExmpl.RandFillUniverse();
    LAExmpl.SetStep(0);
}

void CustomModeGrid(sf::RenderWindow& window)
{
}

void PauseStart(sf::RenderWindow& window)
{
    LAExmpl.pause = !LAExmpl.pause;
}

void Screen(int width, int height, std::string name)
{
    LAExmpl.CreateUniverse();

    sf::RenderWindow window(sf::VideoMode(width, height), name);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(5);

    /* Зоны */
    /* Зона меню */
    sf::Vector2f menuZonePosition = sf::Vector2f(5, 5);
    sf::Vector2f menuZoneSize
            = sf::Vector2f(window.getSize().x * 0.25f, window.getSize().y - 10);

    UserZone menuZone(menuZonePosition, menuZoneSize, &window);
    menuZone.SetDirection(DirectionZoneButtons::VERTICAL);
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
    statusZone.SetDirection(DirectionZoneButtons::HORIZONTAL);
    statusZone.SetFillColor(BLACK_COLOR);
    /* --- */

    /* кнопки */
    UserButton btnRandomMode("RANDOM MODE", &window);
    btnRandomMode.SetFillColor(BLACK_COLOR);
    btnRandomMode.SetSize(sf::Vector2f(200, 60));
    btnRandomMode.ClickButton = RandomGrid;

    UserButton btnCustomMode("CUSTOM MODE", &window);
    btnCustomMode.SetFillColor(BLACK_COLOR);
    btnCustomMode.SetSize(sf::Vector2f(200, 60));
    btnCustomMode.ClickButton = CustomModeGrid;

    UserButton btnClose("CLOSE", &window);
    btnClose.SetSize(sf::Vector2f(100, 60));
    btnClose.SetFillColor(BLACK_COLOR);
    btnClose.ClickButton = CloseWindow;

    UserButton btnPause("PAUSE", &window);
    btnPause.SetSize(sf::Vector2f(80, 60));
    btnPause.SetFillColor(BLACK_COLOR);
    btnPause.ClickButton = PauseStart;
    /* --- */

    menuZone.AddButton(btnCustomMode);
    menuZone.AddButton(btnRandomMode);
    menuZone.AddButton(btnClose);

    statusZone.AddButton(btnPause);

    sf::Clock clock;

    UserButton* casheBtnPause;

    for (int item = 0; item < (int)statusZone.collectionButtons.size();
         item++) {
        if (statusZone.collectionButtons[item].GetButtonName() == "PAUSE")
            casheBtnPause = &statusZone.collectionButtons[item];
    }

    TestInput();

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

        if (LAExmpl.pause)
            casheBtnPause->SetName("START");
        else
            casheBtnPause->SetName("PAUSE");

        if (time1.asMilliseconds() > (LAExmpl.pause ? 9999 : DELAY_MILLIS)) {
            LAExmpl.Step();

            clock.restart();
        }

        sf::Font font;
        font.loadFromFile("fonts/" + DEFAULT_FONT);
        sf::String message = "Step = ";
        message += std::to_string(LAExmpl.GetStep());

        sf::Text textStep(message, font, DEFAULT_FONT_SIZE);

        textStep.setPosition(sf::Vector2f(
                window.getSize().x - 250,
                window.getSize().y - (statusZone.GetSize().y / 2)
                        - (textStep.getGlobalBounds().height / 2)));

        textStep.setFillColor(TANGERINE_COLOR);

        window.draw(textStep);

        // Отрисовка окна
        window.display();
    }
}