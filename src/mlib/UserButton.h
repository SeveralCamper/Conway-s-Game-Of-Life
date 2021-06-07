#ifndef USER_BUTTON_H_
#define USER_BUTTON_H_

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Settings.h"

#include "logic.h"

class UserButton {
private:
    std::string name;

    // Координаты позиции кнопки по умолчанию
    sf::Vector2f position = sf::Vector2f(0, 0);

    // Размер кнопки по умолчанию
    sf::Vector2f size = sf::Vector2f(100, 40);

    // Цвет фона кнопки
    sf::Color color;

    // Шрифт текста кнопки
    sf::Font font;

    sf::RenderWindow* window;

    int midleRectHeight;
    int midleRectWidth;

    int midleTextHeight;
    int midleTextWidth;

    int fontSize = DEFAULT_FONT_SIZE;

    void FitText(sf::Text* textButton);
    void TextAlignCenter(sf::Text* textButton);

public:
    UserButton()
    {
    }

    UserButton(std::string name, sf::RenderWindow* window)
    {
        this->name = name;

        SetFont(DEFAULT_FONT);
        this->color = BLACK_COLOR;

        this->window = window;
    }

    ~UserButton()
    {
        //
    }

    sf::Vector2f GetSize();

    sf::Vector2f GetPosition();

    // Имя кнопки
    std::string GetButtonName();

    void SetSize(sf::Vector2f size);

    void SetName(std::string name);

    // Установка шрифта
    void SetFont(std::string nameFont);

    // Позиция кнопки
    void SetButtonPosition(sf::Vector2f position);

    void SetFillColor(sf::Color color);

    // Отрисовка кнопки
    void DrawButton();

    // Клик мышью в зоне кнопки
    void IsClickButton(sf::Vector2i mousePosition);

    void (*ClickButton)();
};

#endif