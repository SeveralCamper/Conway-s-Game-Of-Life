
#include "ShowGrid.h"
#include "ShowPixel.h"
#include "logic.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class MyButton {
private:
    int ID;
    std::string name;

public:
    MyButton(int ID, std::string name)
    {
        this->ID = ID;
        this->name = name;
    }

    ~MyButton()
    {
        //
    }

    int GetButtonInt()
    {
        return this->ID;
    }

    std::string GetButtonName()
    {
        return this->name;
    }
};

void frame(RenderWindow& window)
{
    window.clear(Color(255, 255, 255));

    RectangleShape rectangle(Vector2f(275.f, 155.f));
    rectangle.setFillColor(Color(0, 0, 0));
    rectangle.setOutlineThickness(2.f);
    rectangle.setOutlineColor(Color(75, 0, 130));
    rectangle.move(2, 2);
    window.draw(rectangle);

    for (int i = 1; i < 5; i++) {
        int y = 129;
        rectangle.move(0, 30 + y);
        window.draw(rectangle);
    }

    RectangleShape rectangle2(Vector2f(1090.f, 790.f));
    rectangle2.setFillColor(Color(255, 136, 0));
    rectangle2.setOutlineThickness(3.f);
    rectangle2.setOutlineColor(Color(75, 0, 130));
    rectangle2.move(281, 2);
    window.draw(rectangle2);

    RectangleShape rectangle3(Vector2f(1040.f, 640.f));
    rectangle3.setFillColor(Color(0, 0, 0));
    rectangle3.setOutlineThickness(3.5f);
    rectangle3.setOutlineColor(Color(75, 0, 130));
    rectangle3.move(305, 30);
    window.draw(rectangle3);
}

void ShowMainButtonMenu(
        RenderWindow& window,
        std::vector<MyButton>& collectionButtonMenu,
        Font font)

{
    int y = 60;
    for (int item = 0; item < (int)collectionButtonMenu.size(); item++) {
        Text text("", font, 40);
        text.setFillColor(Color(255, 136, 0));
        text.setString(collectionButtonMenu[item].GetButtonName());
        text.setPosition(20, y);
        y += 160;
        window.draw(text);
    }
}

void initButton(std::vector<MyButton>& collectionButtonMenu)
{
    MyButton BtnExit(1, "Custom mode");
    collectionButtonMenu.push_back(BtnExit);

    MyButton BtnStart(2, "Exmodelsit");
    collectionButtonMenu.push_back(BtnStart);

    MyButton BtnModels(3, "Random");
    collectionButtonMenu.push_back(BtnModels);

    MyButton BtnRandom(4, "Authors");
    collectionButtonMenu.push_back(BtnRandom);

    MyButton BtnPause(5, "Exit");

    collectionButtonMenu.push_back(BtnPause);
}

int main()
{
    LifeAlgorithm LAExmpl;
    LAExmpl.initLife();
    std::vector<MyButton> collectionButtonMenu;

    initButton(collectionButtonMenu);

    RenderWindow window(sf::VideoMode(1374, 795), "Conway's Game Of Life");

    Font font; //шрифт

    font.loadFromFile("fonts/arial.ttf");

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        sf::Clock clock;
        float time = 0;
        while (time < 1) {
            frame(window);
            ShowMainButtonMenu(window, collectionButtonMenu, font);
            time = clock.getElapsedTime().asSeconds();
            LAExmpl.RunLife();

            ShowGrid(window);

            ShowPixel(window, LAExmpl.fieldArray);

            sf::sleep(sf::milliseconds(300));

            window.display();
        }
        window.display();
    }

    return 0;
}
