#include "UserZone.h"

sf::Vector2f UserZone::GetPosition()
{
    return position;
}

DirectionZoneButtons UserZone::GetDirection()
{
    return direction;
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

void UserZone::SetDirection(DirectionZoneButtons direction)
{
    this->direction = direction;
}

void UserZone::ShowButtons()
{
    int offset = 15;
    int tempPositionY = position.y + offset;
    int tempPositionX = position.x + offset;

    for (int item = 0; item < (int)collectionButtons.size(); item++) {
        sf::Vector2f buttonSize = collectionButtons[item].GetSize();

        switch ((int)direction) {
        case 0:
            collectionButtons[item].SetButtonPosition(sf::Vector2f(
                    tempPositionX,
                    this->position.y + (this->size.y / 2)
                            - collectionButtons[item].GetSize().y / 2));

            tempPositionX += buttonSize.x + offset;
            break;

        case 1:
            collectionButtons[item].SetButtonPosition(sf::Vector2f(
                    (this->size.x / 2)
                            - collectionButtons[item].GetSize().x / 2,
                    tempPositionY));

            tempPositionY += buttonSize.y + offset;
            break;
        default:
            break;
        }

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