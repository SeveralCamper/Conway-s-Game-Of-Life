#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

void frame(RenderWindow & window)
{
	window.clear(Color(255, 255, 255));
	
	RectangleShape rectangle(Vector2f(300.f, 155.f));
	rectangle.setFillColor(Color(255, 255, 255));
	rectangle.setOutlineThickness(6.f);
	rectangle.setOutlineColor(Color(0, 0, 0));
	rectangle.move(20, 30);
	window.draw(rectangle);

	for(int i = 1; i < 4; i++)
	{
		int y = 130;
		rectangle.move(0, 30 + y);
		window.draw(rectangle);
	}

	RectangleShape rectangle2(Vector2f(900.f, 635.f));
	rectangle2.setFillColor(Color(255, 255, 255));
	rectangle2.setOutlineThickness(6.f);
	rectangle2.setOutlineColor(Color(0, 0, 0));
	rectangle2.move(300, 30);
	window.draw(rectangle2);

	RectangleShape rectangle3(Vector2f(850.f, 530.f));
	rectangle3.setFillColor(Color(255, 255, 255));
	rectangle3.setOutlineThickness(6.f);
	rectangle3.setOutlineColor(Color(0, 0, 0));
	rectangle3.move(325, 60);
	window.draw(rectangle3);
}

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
	menu2.setPosition(20, 185);
	menu3.setPosition(20, 340);
	menu4.setPosition(16, 495);
 
	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menu4.setColor(Color::White);

		menuNum = 0;
		//window.clear(Color(255, 255, 255));
 
		if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Red); menuNum = 1; }
		if (IntRect(100, 185, 300, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Red); menuNum = 2; }
		if (IntRect(100, 340, 300, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Red); menuNum = 3; }
		if (IntRect(100, 495, 300, 50).contains(Mouse::getPosition(window))) { menu4.setColor(Color::Red); menuNum = 4; }

 
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
    RenderWindow window(sf::VideoMode(1300, 700), "LIFE");
	
	while (window.isOpen())
	{
		Event event;
  		while (window.pollEvent(event))
  		{
   			if (event.type == Event::Closed) window.close();
  		}

	frame(window);  
	menu(window);//вызов меню

	window.display();
	}

	

    return 0;
}