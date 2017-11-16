#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "Config.h"
#include "Model.h"
#include "Control.h"

using namespace sf;

int main()
{
    float Yold=0;
    int pos=0 ,velocity;

    string name;
    string imageTexture = "Texture/sand.png";
    std::cout<<"Input name:  ";
    std::cin>>name;
    Lander lander(name);
    system("pause");


    RenderWindow window(VideoMode(windowWidth, windowHeigh), "LunarLander");

    Image lander_img;
	lander_img.loadFromFile(imageTexture);

	Texture lander_texture;
	lander_texture.loadFromImage(lander_img);

	Sprite lander_sprite;
	lander_sprite.setTexture(lander_texture);
	lander_sprite.setPosition(300, 300);



    while (window.isOpen())
    {

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
                std::cout<<"Window is close"<<"\n";
                window.close();
        }

        float Y = lander_sprite.getPosition().y;

        if(Yold==0)
        {
            Yold = Y;
        }

        if (Y < 584)
        {
            pos = Y - Yold;
            if(pos==2)
            {
                Yold = 0;
                pos = 0;
                velocity = lander.getVelocity();
                lander.setVelocity(velocity+1);
                velocity = lander.getVelocity();
            }
            lander_sprite.setPosition(300, Y+gravity);
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            lander_sprite.setPosition(300, Y - 0.042);

            //velocity = lander.getVelocity();
            //lander.setVelocity(velocity-0.00000001);
        }

        //std::cout<<"Velocity: "<<velocity<<"\n";
        std::cout<<pos<<"\n";
        window.clear(Color(0,0,0));
        window.draw(lander_sprite);
        window.display();
    }

    system("pause");
    return 0;
}
