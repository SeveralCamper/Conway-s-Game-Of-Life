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

    sf::Vector2i GetSize();

    void SetSize(int width, int height);

    // Установка шрифта
    void SetFont(std::string nameFont);

    // Имя кнопки
    std::string GetButtonName();

    // Позиция кнопки
    void SetButtonPosition(int xPosition, int yPosition);

    void SetFillColor(sf::Color color);

    // Отрисовка кнопки
    void DrawButton();

    // Клик мышью в зоне кнопки
    void IsClickButton(sf::Vector2i mousePosition);

    void (*ClickButton)(sf::RenderWindow&);
};

#endif