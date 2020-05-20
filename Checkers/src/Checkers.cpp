    ////////////////////////////////////////
   //       Checkers by SnegirSoft       //
  //                                    //
 //  File: Checkers.cpp                //
////////////////////////////////////////

#include "Classes/Field.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(CHECKER_SIZE * FIELD_SIZE, CHECKER_SIZE * FIELD_SIZE), "Checkers");

	ResourceManager rm;
	Field field(rm);

	sf::Clock clock;
	while (window.isOpen())
	{
		float delta = clock.getElapsedTime().asMilliseconds();
		clock.restart();
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();
		field.draw(window);
		window.display();
	}
}