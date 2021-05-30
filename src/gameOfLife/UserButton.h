#ifndef _USER_BUTTON_
#define _USER_BUTTON_

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

        //  По дефолту ставим значения
        this->buttonPositionX = x;
        this->buttonPositionY = y;

        this->width = width;
        this->height = height;

        this->color = sf::Color(255, 255, 255);

        this->window = window;
    }

    ~UserButton()
    {
        //
    }

    /*     UserButton& Less()
        {
            std::cout << "ups" << std::endl;
            return *this;
        } */

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
    sf::RectangleShape DrawButton()
    {
        sf::RectangleShape rectButton(sf::Vector2f(this->width, this->height));
        rectButton.setFillColor(this->color);

        rectButton.setOutlineThickness(6.f);

        return rectButton;
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