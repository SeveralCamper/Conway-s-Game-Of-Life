#include "UserZone.h"

// Позиция зоны
void UserZone::SetZonePosition(int xPosition, int yPosition)
{
    this->zonePositionX = xPosition;
    this->zonePositionY = yPosition;
}

void UserZone::SetZoneSize(int width, int height)
{
    this->height = height;
    this->width = width;
}

void UserZone::PushButton(UserButton userButton)
{
    collectionButtons.push_back(userButton);
}

void UserZone::SetFillColor(sf::Color color)
{
    this->color = color;
}

void UserZone::ShowButtons()
{
    for (int item = 0; item < (int)collectionButtons.size(); item++) {
        sf::Vector2i buttonSize = collectionButtons[item].GetSize();

        collectionButtons[item].SetSize(height, buttonSize.y);
        collectionButtons[item].SetButtonPosition(
                zonePositionX, (zonePositionY + buttonSize.y + 5) * item);

        collectionButtons[item].DrawButton();
        collectionButtons[item].IsClickButton(sf::Mouse::getPosition(*window));
    }
}

// Отрисовка зоны
void UserZone::DrawZone()
{
    std::cout << "debug3" << std::endl;
    sf::RectangleShape zone;

    zone.setSize(sf::Vector2f(height, width));

    zone.setPosition(sf::Vector2f(zonePositionX, zonePositionY));

    zone.setFillColor(this->color);

    window->draw(zone);

    ShowButtons();
}