#include <SFML/Graphics.hpp>
// #include <SFML/Audio.hpp> - через SFML
// можно работать с аудио-функциями с помощью
// подключения данной библиотеки

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), " \"Sea Battle\" by Misha Alkhimovich");

    sf::Image Fieldimage; //создаем объект Image (изображение)
	Fieldimage.loadFromFile("image/Field.png");//загружаем в него файл
 
	sf::Texture Fieldtexture;//создаем объект Texture (текстура)
	Fieldtexture.loadFromImage(Fieldimage);//передаем в него объект Image (изображения)
 
	sf::Sprite Fieldsprite;//создаем объект Sprite(спрайт)
	Fieldsprite.setTexture(Fieldtexture);//передаём в него объект Texture (текстуры)
	Fieldsprite.setPosition(750, 280);//задаем начальные координаты появления спрайта

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(Fieldsprite);
        window.display();
    }

    return 0;
}