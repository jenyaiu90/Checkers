    ////////////////////////////////////////
   //       Checkers by SnegirSoft       //
  //                                    //
 //  File: Checkers.cpp                //
////////////////////////////////////////

#include <iostream>
#include "Classes/Options.h"

int main()
{
	try
	{
		Log::clear();
		Log_i(I_START);

		sf::RenderWindow window(sf::VideoMode(CHECKER_SIZE * FIELD_SIZE, CHECKER_SIZE * (FIELD_SIZE + 1)), PROGRAM_NAME + ", " + PROGRAM_VERSION);
		sf::Image image;
		if (image.loadFromFile(TEXTURES_PATH + ICON_FILE + TEXTURES_EXT))
		{
			Log_d(DEBUG + D_FILE_LOADED + TEXTURES_PATH + ICON_FILE + TEXTURES_EXT);
		}
		else
		{
			Log_w(WARNING + E_NO_FILE + TEXTURES_PATH + ICON_FILE + TEXTURES_EXT);
		}
		window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());


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

		sf::Sprite logo;
		logo.setTexture(rm.get_logo_texture());
		logo.setColor(sf::Color(255, 255, 255, 0));
		logo.setPosition((CHECKER_SIZE * FIELD_SIZE - logo.getTexture()->getSize().x) / 2,
			(CHECKER_SIZE * FIELD_SIZE - logo.getTexture()->getSize().y) / 2);

		sf::Clock clock;
		float time = 0;
		while (window.isOpen() && time <= 3000)
		{
			time = clock.getElapsedTime().asMilliseconds();
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
					Log_i(I_END);
				}
			}
			
			float alpha = 255 * (-0.8 * (time / 1000) * (time / 1000) + 2.4 * (time / 1000));
			if (alpha > 255)
			{
				alpha = 255;
			}
			logo.setColor(sf::Color(255, 255, 255, alpha));

			window.clear(sf::Color(255, 255, 255));
			window.draw(logo);
			window.display();
		}

		sf::Sprite opt;
		opt.setTexture(rm.get_buttons_texture());
		opt.setTextureRect(sf::IntRect(OPTIONS_BT_TEXTURE[0] * CHECKER_SIZE, OPTIONS_BT_TEXTURE[1] * CHECKER_SIZE, CHECKER_SIZE, CHECKER_SIZE));
		opt.setPosition((FIELD_SIZE - 1) * CHECKER_SIZE, FIELD_SIZE * CHECKER_SIZE);

		Options options(rm);
		bool options_opened = false;

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
					if (options_opened)
					{
						options_opened = !options.click(sf::Mouse::getPosition(window), field, current_color);
					}
					else
					{
						bool options_click = false;
						if (field.click(sf::Mouse::getPosition(window), moves, current_color, options_click))
						{
							Field::delete_moveLL(moves);
							bool eat_again;
							moves = field.get_moves(current_color, eat_again);
							if (!eat || !eat_again)
							{
								if (options.get_turn_mode())
								{
									field.turn();
								}
								current_color = current_color == Checker::WHITE ? Checker::BLACK : Checker::WHITE;
								Field::delete_moveLL(moves);
								moves = field.get_moves(current_color, eat_again);
								if (moves->from == moves->to && moves->next == nullptr)
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
						if (options_click)
						{
							options_opened = true;
						}
					}
				}
			}

			window.clear();
			field.draw(window);
			window.draw(current_move);
			if (options_opened)
			{
				options.draw(window);
			}
			else
			{
				window.draw(opt);
			}
			window.display();
		}

		window.clear();
		field.draw(window);
		current_move.setTextureRect(sf::IntRect(
			current_color == Checker::BLACK ? WHITE_Q_TEXTURE * CHECKER_SIZE : BLACK_Q_TEXTURE * CHECKER_SIZE,
			0, CHECKER_SIZE, CHECKER_SIZE));
		current_move.setScale(sf::Vector2f(6, 6));
		current_move.setPosition(sf::Vector2f(CHECKER_SIZE * (FIELD_SIZE / 2 - 3), CHECKER_SIZE * (FIELD_SIZE / 2 - 3)));
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
	return 0;
}