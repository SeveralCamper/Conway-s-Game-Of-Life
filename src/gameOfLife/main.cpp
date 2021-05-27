#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

void menu(RenderWindow & window) {
	Texture menuTexture1, menuTexture2, menuTexture3, menuTexture4,aboutTexture;
	menuTexture1.loadFromFile("image/111.png");
	menuTexture2.loadFromFile("image/222.png");
	menuTexture3.loadFromFile("image/333.png");
	menuTexture4.loadFromFile("image/444.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), menu4(menuTexture4), about(aboutTexture);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(20, 30);
	menu2.setPosition(20, 140);
	menu3.setPosition(20, 240);
	menu4.setPosition(20, 400);
 
	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menu4.setColor(Color::White);

		menuNum = 0;
		window.clear(Color(255, 255, 255));
 
		if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
		if (IntRect(100, 90, 300, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }
		if (IntRect(100, 150, 300, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }
		if (IntRect(100, 210, 300, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 4; }

 
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { window.close(); isMenu = false; }
			if (menuNum == 3)  { window.close(); isMenu = false; }
			if (menuNum == 4) {  window.close(); isMenu = false; }
 
		}
 
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.draw(menu4);

		
		window.display();
	}
	////////////////////////////////////////////////////
}

int main(int argc, const char** argv) {
    RenderWindow window(sf::VideoMode(1376, 768), "LIFE");
	
	while (window.isOpen())
	{
		Event event;
  		while (window.pollEvent(event))
  		{
   			if (event.type == Event::Closed) window.close();
  		}
	menu(window);//вызов меню

	window.display();
	}

	

    return 0;
}