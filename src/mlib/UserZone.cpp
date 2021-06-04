#include "UserZone.h"

sf::Vector2f UserZone::GetPosition()
{
    return position;
}

// Позиция зоны
void UserZone::SetZonePosition(sf::Vector2f position)
{
    this->position = position;
}

void UserZone::SetZoneSize(sf::Vector2f size)
{
    this->size = size;
}

void UserZone::AddButton(UserButton userButton)
{
    collectionButtons.push_back(userButton);
}

void UserZone::SetFillColor(sf::Color color)
{
    this->color = color;
}

void UserZone::ShowButtons()
{
    int offset = 15;
    int tempPositionY = position.y + offset;

    for (int item = 0; item < (int)collectionButtons.size(); item++) {
        sf::Vector2f buttonSize = collectionButtons[item].GetSize();

        collectionButtons[item].SetButtonPosition(  
            sf::Vector2f(
                tempPositionY, 
                (this->size.y / 2) - collectionButtons[item].GetSize().x / 2)
            );

        tempPositionY += buttonSize.y + offset;

        collectionButtons[item].DrawButton();
        collectionButtons[item].IsClickButton(sf::Mouse::getPosition(*window));
    }
}

// Отрисовка зоны
void UserZone::DrawZone()
{
    sf::RectangleShape zone;

    zone.setSize(size);

    zone.setPosition(position);

    zone.setFillColor(this->color);

    window->draw(zone);

    ShowButtons();
}