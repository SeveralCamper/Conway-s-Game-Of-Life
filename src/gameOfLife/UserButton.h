#ifndef USER_BUTTON_H_
#define USER_BUTTON_H_

#include <SFML/Graphics.hpp>
#include <iostream>
class UserButton {
private:
    std::string name;

    // Координаты позиции кнопки
    int buttonPositionX = 100;
    int buttonPositionY = 100;

    // Размер кнопки
    float width = 100;
    float height = 30;

    // Цвет фона кнопки
    sf::Color color;

    // Шрифт текста кнопки
    sf::Font font;

    sf::RenderWindow* window;

public:
    UserButton(
            std::string name,
            int x,
            int y,
            float width,
            float height,
            sf::RenderWindow* window)
    {
        this->name = name;

        this->buttonPositionX = x;
        this->buttonPositionY = y;

        this->width = width;
        this->height = height;

        //  По дефолту ставим значения

        SetFont("arial.ttf");

        this->color = sf::Color(255, 255, 255);

        this->window = window;
    }

    ~UserButton()
    {
        //
    }

    sf::Vector2i GetSize()
    {
        return sf::Vector2i(width, height);
    }

    void SetSize(int width, int height)
    {
        this->height = height;
        this->width = width;
    }

    // Установка шрифта
    void SetFont(std::string nameFont)
    {
        font.loadFromFile("fonts/" + nameFont);
    }

    // Имя кнопки
    std::string GetButtonName()
    {
        return this->name;
    }

    // Позиция кнопки
    void SetButtonPosition(int xPosition, int yPosition)
    {
        this->buttonPositionX = xPosition;
        this->buttonPositionY = yPosition;
    }

    void SetFillColor(sf::Color color)
    {
        this->color = color;
    }

    // Отрисовка кнопки
    void DrawButton()
    {
        int midleRectHeight;
        int midleRectWidth;

        int midleTextHeight;
        int midleTextWidth;

        sf::RectangleShape rectButton(sf::Vector2f(this->width, this->height));

        rectButton.setPosition(this->buttonPositionX, this->buttonPositionY);
        rectButton.setFillColor(this->color);

        rectButton.setOutlineThickness(-4.f);

        sf::Color colorTextBtn = sf::Color(123, 2, 55);

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
    void IsClickButton(sf::Vector2i mousePosition)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (mousePosition.x > buttonPositionX
                && mousePosition.x < buttonPositionX + width
                && mousePosition.y > buttonPositionY
                && mousePosition.y < buttonPositionY + height)
                ClickButton(*window);
        }
    }

    void (*ClickButton)(sf::RenderWindow&);
};

#endif