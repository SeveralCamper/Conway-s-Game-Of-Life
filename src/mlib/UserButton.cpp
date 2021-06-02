#include "UserButton.h"

sf::Vector2i UserButton::GetSize()
{
    return sf::Vector2i(width, height);
}

void UserButton::SetSize(int width, int height)
{
    this->height = height;
    this->width = width;
}

// Установка шрифта
void UserButton::SetFont(std::string nameFont)
{
    font.loadFromFile("fonts/" + nameFont);
}

// Имя кнопки
std::string UserButton::GetButtonName()
{
    return this->name;
}

// Позиция кнопки
void UserButton::SetButtonPosition(int xPosition, int yPosition)
{
    this->buttonPositionX = xPosition;
    this->buttonPositionY = yPosition;
}

void UserButton::SetFillColor(sf::Color color)
{
    this->color = color;
}

// Отрисовка кнопки
void UserButton::DrawButton()
{
    int midleRectHeight;
    int midleRectWidth;

    int midleTextHeight;
    int midleTextWidth;

    sf::RectangleShape rectButton(sf::Vector2f(this->width, this->height));

    rectButton.setPosition(this->buttonPositionX, (this->buttonPositionY) + 5);
    rectButton.setFillColor(this->color);

    rectButton.setOutlineThickness(-4.f);
    rectButton.setOutlineColor(sf::Color(75, 0, 130));

    sf::Color colorTextBtn = sf::Color(255, 136, 0);

    sf::Text text(this->name, font, 20);

    text.setFillColor(colorTextBtn);
    text.setOutlineColor(colorTextBtn);
    text.setStyle(sf::Text::Bold);

    midleRectHeight = this->width / 2;
    midleRectWidth = this->height / 2;

    midleTextHeight = text.getGlobalBounds().height / 2;
    midleTextWidth = text.getGlobalBounds().width / 2;

    text.setPosition(
            this->buttonPositionX + midleRectHeight - midleTextWidth,
            this->buttonPositionY + midleRectWidth - midleTextHeight);

    window->draw(rectButton);
    window->draw(text);
}

// Клик мышью в зоне кнопки
void UserButton::IsClickButton(sf::Vector2i mousePosition)
{
    std::cout << "debug" << std::endl;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (mousePosition.x > buttonPositionX
            && mousePosition.x < buttonPositionX + width
            && mousePosition.y > buttonPositionY
            && mousePosition.y < buttonPositionY + height)
            ClickButton(*window);
    }
}

void (*ClickButton)(sf::RenderWindow&);