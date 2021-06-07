#ifndef USER_ZONE_H_
#define USER_ZONE_H_

#include "Settings.h"
#include "UserButton.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class UserZone {
private:
    // Координаты позиции зоны по умолчанию
    sf::Vector2f position = sf::Vector2f(0, 0);

    // Размер зоны по умолчанию
    sf::Vector2f size = sf::Vector2f(100, 100);

    sf::Color color;

    DirectionZoneButtons direction;

    sf::RenderWindow* window;

public:
    std::vector<UserButton> collectionButtons;

    UserZone(sf::Vector2f position, sf::Vector2f size, sf::RenderWindow* window)
    {
        this->position = position;
        this->size = size;
        this->window = window;
        this->color = WHITE_COLOR;
    }

    ~UserZone()
    {
        //
    }

    sf::Vector2f GetPosition();
    sf::Vector2f GetSize();

    DirectionZoneButtons GetDirection();

    // Позиция зоны
    void SetPosition(sf::Vector2f position);

    void SetWindow(sf::RenderWindow* window);

    void SetSize(sf::Vector2f size);

    void AddButton(UserButton userButton);

    void SetFillColor(sf::Color color);

    void SetDirection(DirectionZoneButtons direction);

    void ShowButtons();

    // Отрисовка зоны
    void DrawZone();
};

#endif