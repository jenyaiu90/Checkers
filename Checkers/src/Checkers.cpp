    ////////////////////////////////////////
   //       Checkers by SnegirSoft       //
  //                                    //
 //  File: Checkers.cpp                //
////////////////////////////////////////

#include <iostream>
#include "Classes/Field.h"

int main()
{
	Log::clear();
	Log::debugEnable();
	Log_i(I_START);

	sf::RenderWindow window(sf::VideoMode(CHECKER_SIZE * FIELD_SIZE, CHECKER_SIZE * FIELD_SIZE), PROGRAM_NAME);

	ResourceManager rm;
	Field field(rm);

	sf::Clock clock;
	
	Log_i(I_GAME_START);
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
				Log_i(I_END);
			}
		}

		system("cls");
		std::cout << "FPS: " << 1 / (delta / 1000);

		window.clear();
		field.draw(window);
		window.display();
	}
}