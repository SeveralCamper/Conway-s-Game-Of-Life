#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

void menu(RenderWindow & window) {
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	menuTexture1.loadFromFile("image/111.png");
	menuTexture2.loadFromFile("image/222.png");
	menuTexture3.loadFromFile("image/333.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(100, 30);
	menu2.setPosition(100, 90);
	menu3.setPosition(100, 150);
	menuBg.setPosition(345, 0);
 
	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{
		
	}
}

int main() {
    RenderWindow window(sf::VideoMode(1376, 768), "LIFE");
	
	Event event;
  	while (window.pollEvent(event))
  	{
   	if (event.type == Event::Closed) window.close();
  	}

    return 0;
}