#ifndef USER_ZONE_H_
#define USER_ZONE_H_

#include <SFML/Graphics.hpp>
#include <iostream>

#include "UserButton.h"

class UserZone {
private:
    // Координаты позиции зоны
    int zonePositionX = 0;
    int zonePositionY = 0;

    // Размер зоны
    float width = 0;
    float height = 0;

    sf::Color color;

    sf::RenderWindow* window;

public:
    std::vector<UserButton> collectionButtons;

    UserZone(int x, int y, float width, float height, sf::RenderWindow* window)
    {
        this->zonePositionX = x;
        this->zonePositionY = y;

        this->width = width;
        this->height = height;
        this->window = window;

        this->color = sf::Color(255, 255, 255);
    }

    ~UserZone()
    {
        //
    }

    // Позиция зоны
    void SetZonePosition(int xPosition, int yPosition);

    void SetZoneSize(int width, int height);

    void PushButton(UserButton userButton);

    void SetFillColor(sf::Color color);

    void ShowButtons();

    // Отрисовка зоны
    void DrawZone();
};


#endif