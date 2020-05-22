    ////////////////////////////////////////
   //       Checkers by SnegirSoft       //
  //                                    //
 //  File: Checkers.cpp                //
////////////////////////////////////////

#include <iostream>
#include "Classes/Field.h"

int main()
{
	try
	{
		Log::clear();
		Log::debugEnable();
		Log_i(I_START);

		sf::RenderWindow window(sf::VideoMode(CHECKER_SIZE * FIELD_SIZE, CHECKER_SIZE * (FIELD_SIZE + 1)), PROGRAM_NAME);

		ResourceManager rm;
		Field field(rm);
		sf::Sprite current_move;
		current_move.setTexture(rm.get_checkers_texture());
		current_move.setTextureRect(sf::IntRect(WHITE_TEXTURE * CHECKER_SIZE, UNSELECTED_TEXTURE * CHECKER_SIZE, CHECKER_SIZE, CHECKER_SIZE));
		current_move.setPosition(sf::Vector2f(0, CHECKER_SIZE * FIELD_SIZE));

		Checker::Color current_color = Checker::WHITE;
		bool eat;
		bool game = true;
		Field::MoveLL* moves = field.get_moves(current_color, eat);

		sf::Clock clock;

		Log_i(I_GAME_START);
		while (window.isOpen() && game)
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
				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (field.click(sf::Mouse::getPosition(window), moves, current_color))
					{
						Field::delete_moveLL(moves);
						bool eat_again;
						moves = field.get_moves(current_color, eat_again);
						if (!eat || !eat_again)
						{
							current_color = current_color == Checker::WHITE ? Checker::BLACK : Checker::WHITE;
							Field::delete_moveLL(moves);
							moves = field.get_moves(current_color, eat_again);
							if (moves == nullptr)
							{
								game = false;
								break;
							}
							current_move.setTextureRect(sf::IntRect(
								current_color == Checker::WHITE ? WHITE_TEXTURE * CHECKER_SIZE : BLACK_TEXTURE * CHECKER_SIZE,
								0, CHECKER_SIZE, CHECKER_SIZE));
						}
						eat = eat_again;
					}
				}
			}

			window.clear();
			field.draw(window);
			window.draw(current_move);
			window.display();
		}

		current_move.setTextureRect(sf::IntRect(
			current_color == Checker::BLACK ? WHITE_Q_TEXTURE * CHECKER_SIZE : BLACK_Q_TEXTURE * CHECKER_SIZE,
			0, CHECKER_SIZE, CHECKER_SIZE));
		current_move.setScale(sf::Vector2f(10, 10));
		current_move.setPosition(sf::Vector2f(FIELD_SIZE * CHECKER_SIZE * 2.5, FIELD_SIZE * CHECKER_SIZE * 2.5));
		window.draw(current_move);
		window.display();

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
					Log_i(I_END);
				}
			}
		}
	}
	catch (std::exception e)
	{
		std::cout << ERROR << e.what();
		system((LOG_FILE + TEXT_EXT).c_str());
	}
}