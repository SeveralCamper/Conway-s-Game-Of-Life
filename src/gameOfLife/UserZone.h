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
    }

    ~UserZone()
    {
        //
    }

    // Позиция зоны
    void SetZonePosition(int xPosition, int yPosition)
    {
        this->zonePositionX = xPosition;
        this->zonePositionY = yPosition;
    }

    void SetZoneSize(int width, int height)
    {
        this->height = height;
        this->width = width;
    }

    void PushButton(UserButton userButton)
    {
        collectionButtons.push_back(userButton);
    }

    void ShowButtons()
    {
        for (int item = 0; item < (int)collectionButtons.size(); item++) {
            
            sf::Vector2i buttonSize = collectionButtons[item].GetSize();

            collectionButtons[item].SetSize(height, buttonSize.y);
            collectionButtons[item].SetButtonPosition(
                    zonePositionX, (zonePositionY  + buttonSize.y + 5 ) * item);

            collectionButtons[item].DrawButton();
            collectionButtons[item].IsClickButton(
                    sf::Mouse::getPosition(*window));

            
        }
    }

    // Отрисовка зоны
    void DrawZone()
    {
        sf::RectangleShape zone;

        zone.setSize(sf::Vector2f(height, width));

        zone.setPosition(sf::Vector2f(zonePositionX, zonePositionY));

        zone.setFillColor(sf::Color(124, 12, 35));

        window->draw(zone);

       ShowButtons();
    }
};

#endif