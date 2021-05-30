#include <SFML/Graphics.hpp>
#include <iostream>

#include "Screen.h"
#include "UserButton.h"

/*
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
    rectangle3.setFillColor(Color(255, 255, 255));
    rectangle3.setOutlineThickness(3.5f);
    rectangle3.setOutlineColor(Color(75, 0, 130));
    rectangle3.move(305, 30);
    window.draw(rectangle3);
}
 */
void ShowMainButtonMenu(
        sf::RenderWindow& window,
        std::vector<UserButton>& collectionButtonMenu,
        sf::Font font)

{
    int y = 60;
    for (int item = 0; item < (int)collectionButtonMenu.size(); item++) {
        sf::Text text("", font, 40);
        text.setFillColor(sf::Color(255, 136, 0));
        text.setString(collectionButtonMenu[item].GetButtonName());
        text.setPosition(20, y);
        y += 160;
        window.draw(text);

        /*RectangleShape rectButton(Vector2f(300.f, 155.f));
        rectButton.setFillColor(Color(255, 255, 255));
        rectButton.setOutlineThickness(6.f);
        rectButton.setOutlineColor(Color(0, 0, 0));
        rectButton.move(20, 30);

        window.draw(rectButton);*/

        // window.display();
    }

    /*     Texture menuTexture1, menuTexture2, menuTexture3, menuTexture4,
                aboutTexture;

        menuTexture1.loadFromFile("image/111.png");
        menuTexture2.loadFromFile("image/222.png");
        menuTexture3.loadFromFile("image/333.png");
        menuTexture4.loadFromFile("image/444.png");
        Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3),
                menu4(menuTexture4), about(aboutTexture);
        bool isMenu = 1;
        int menuNum = 0;
        menu1.setPosition(20, 30);
        menu2.setPosition(20, 185);
        menu3.setPosition(20, 340);
        menu4.setPosition(16, 495);

        //////////////////////////////МЕНЮ///////////////////
        while (isMenu) {
            menu1.setColor(Color::White);
            menu2.setColor(Color::White);
            menu3.setColor(Color::White);
            menu4.setColor(Color::White);

            menuNum = 0;
            // window.clear(Color(255, 255, 255));

            if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window)))
       { menu1.setColor(Color::Red); menuNum = 1;
            }
            if (IntRect(100, 185, 300, 50).contains(Mouse::getPosition(window)))
       { menu2.setColor(Color::Red); menuNum = 2;
            }
            if (IntRect(100, 340, 300, 50).contains(Mouse::getPosition(window)))
       { menu3.setColor(Color::Red); menuNum = 3;
            }
            if (IntRect(100, 495, 300, 50).contains(Mouse::getPosition(window)))
       { menu4.setColor(Color::Red); menuNum = 4;
            }

            if (Mouse::isButtonPressed(Mouse::Left)) {
                if (menuNum == 1)
                    isMenu = false; //если нажали первую кнопку, то выходим из
       меню if (menuNum == 2) { window.close(); isMenu = false;
                }
                if (menuNum == 3) {
                    window.close();
                    isMenu = false;
                }
                if (menuNum == 4) {
                    window.close();
                    isMenu = false;
                }
            }

            window.draw(menu1);
            window.draw(menu2);
            window.draw(menu3);
            window.draw(menu4); */

    //}
    ////////////////////////////////////////////////////
}

void initButton(
        std::vector<UserButton>& collectionButtonMenu, sf::RenderWindow& window)
{
    // UserButton BtnExit(1, "Custom mode", window);
    // collectionButtonMenu.push_back(BtnExit);

    /*  UserButton BtnStart(2, "Exmodelsit");
     collectionButtonMenu.push_back(BtnStart);

     UserButton BtnModels(3, "Random");
     collectionButtonMenu.push_back(BtnModels);

     UserButton BtnRandom(4, "Authors");
     collectionButtonMenu.push_back(BtnRandom);

     UserButton BtnPause(5, "Exit");

     collectionButtonMenu.push_back(BtnPause); */
}

int main(int argc, const char** argv)
{
    // Отрисовка окна программы
    Screen(1374, 795, "Life");

    return 0;
}