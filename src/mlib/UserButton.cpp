#include "UserButton.h"

sf::Vector2f UserButton::GetSize()
{
    return size;
}

sf::Vector2f UserButton::GetPosition()
{
    return position;
}

void UserButton::SetSize(sf::Vector2f size)
{
    this->size = size;
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
void UserButton::SetButtonPosition(sf::Vector2f position)
{
    this->position = position;
}

void UserButton::SetName(std::string name)
{
    this->name = name;
}

void UserButton::SetFillColor(sf::Color color)
{
    this->color = color;
}

// Подгонка размера текста кнопки под размер кнопки
void UserButton::FitText(sf::Text* textButton)
{
    if (textButton->getGlobalBounds().width > this->size.x) {
        bool okSize = false;

        int ratio = 1;

        while (!okSize) {
            if (textButton->getGlobalBounds().width > this->size.x) {
                textButton->setCharacterSize(DEFAULT_FONT_SIZE - ratio);
                ratio++;
            } else {
                okSize = true;
                this->fontSize = DEFAULT_FONT_SIZE - ratio - 1;
            }
        }
    }
}

void UserButton::TextAlignCenter(sf::Text* textButton)
{
    midleRectHeight = this->size.y / 2;
    midleRectWidth = this->size.x / 2;

    midleTextHeight = textButton->getGlobalBounds().height / 2;
    midleTextWidth = textButton->getGlobalBounds().width / 2;

    textButton->setPosition(
            this->position.x + midleRectWidth - midleTextWidth,
            this->position.y + midleRectHeight - midleTextHeight);
}

// Отрисовка кнопки
void UserButton::DrawButton()
{
    sf::RectangleShape rectButton(size);

    rectButton.setPosition(position);
    rectButton.setFillColor(this->color);

    rectButton.setOutlineThickness(4.f);
    rectButton.setOutlineColor(INDIGO_COLOR);

    sf::Text textButton(this->name, font, this->fontSize);

    textButton.setFillColor(TANGERINE_COLOR);
    textButton.setOutlineColor(INDIGO_COLOR);
    textButton.setStyle(sf::Text::Bold | sf::Text::Italic);

    FitText(&textButton);
    TextAlignCenter(&textButton);

    window->draw(rectButton);
    window->draw(textButton);
}

// Клик мышью в зоне кнопки
void UserButton::IsClickButton(sf::Vector2i mousePosition)
{
  //  std::cout << "Button" << std::endl;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if ((mousePosition.x > position.x
             && mousePosition.x < position.x + size.x)
            && (mousePosition.y > position.y
                && mousePosition.y < position.y + size.y))
            ClickButton(*window);
    }
}

void (*ClickButton)(sf::RenderWindow&);