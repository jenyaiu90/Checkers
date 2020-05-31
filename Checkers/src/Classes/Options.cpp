    ////////////////////////////////////////
   //       Checkers by SnegirSoft       //
  //                                    //
 //  File: Options.cpp                 //
////////////////////////////////////////

#include "Options.h"
#include <thread>

Options::Options(ResourceManager& rm)
{
	_debug_mode = false;
	_turn_mode = true;

	_window.setTexture(rm.get_options_window_texture());
	_window.setPosition(0, 0);
	
	sf::IntRect rect(0, 0, CHECKER_SIZE, CHECKER_SIZE);
	
	rect.left = SELECTED_BT_TEXTURE[0] * CHECKER_SIZE;
	rect.top = SELECTED_BT_TEXTURE[1] * CHECKER_SIZE;
	_turn_bg.setTexture(rm.get_buttons_texture());
	_turn_bg.setTextureRect(rect);
	_turn_bg.setPosition(TURN_BT_POS[0] * CHECKER_SIZE, TURN_BT_POS[1] * CHECKER_SIZE);

	rect.left = UNSELECTED_BT_TEXTURE[0] * CHECKER_SIZE;
	rect.top = UNSELECTED_BT_TEXTURE[1] * CHECKER_SIZE;
	_debug_bg.setTexture(rm.get_buttons_texture());
	_debug_bg.setTextureRect(rect);
	_debug_bg.setPosition(DEBUG_BT_POS[0] * CHECKER_SIZE, DEBUG_BT_POS[1] * CHECKER_SIZE);

	_close_bg.setTexture(rm.get_buttons_texture());
	_close_bg.setTextureRect(rect);
	_close_bg.setPosition(CLOSE_BT_POS[0] * CHECKER_SIZE, CLOSE_BT_POS[1] * CHECKER_SIZE);

	_info_bg.setTexture(rm.get_buttons_texture());
	_info_bg.setTextureRect(rect);
	_info_bg.setPosition(INFO_BT_POS[0] * CHECKER_SIZE, INFO_BT_POS[1] * CHECKER_SIZE);
	

	rect.left = TURN_BT_TEXTURE[0] * CHECKER_SIZE;
	rect.top = TURN_BT_TEXTURE[1] * CHECKER_SIZE;
	_turn_bt.setTexture(rm.get_buttons_texture());
	_turn_bt.setTextureRect(rect);
	_turn_bt.setPosition(TURN_BT_POS[0] * CHECKER_SIZE, TURN_BT_POS[1] * CHECKER_SIZE);
	
	rect.left = DEBUG_BT_TEXTURE[0] * CHECKER_SIZE;
	rect.top = DEBUG_BT_TEXTURE[1] * CHECKER_SIZE;
	_debug_bt.setTexture(rm.get_buttons_texture());
	_debug_bt.setTextureRect(rect);
	_debug_bt.setPosition(DEBUG_BT_POS[0] * CHECKER_SIZE, DEBUG_BT_POS[1] * CHECKER_SIZE);
	
	rect.left = CLOSE_BT_TEXTURE[0] * CHECKER_SIZE;
	rect.top = CLOSE_BT_TEXTURE[1] * CHECKER_SIZE;
	_close_bt.setTexture(rm.get_buttons_texture());
	_close_bt.setTextureRect(rect);
	_close_bt.setPosition(CLOSE_BT_POS[0] * CHECKER_SIZE, CLOSE_BT_POS[1] * CHECKER_SIZE);
	
	rect.left = INFO_BT_TEXTURE[0] * CHECKER_SIZE;
	rect.top = INFO_BT_TEXTURE[1] * CHECKER_SIZE;
	_info_bt.setTexture(rm.get_buttons_texture());
	_info_bt.setTextureRect(rect);
	_info_bt.setPosition(INFO_BT_POS[0] * CHECKER_SIZE, INFO_BT_POS[1] * CHECKER_SIZE);
}

void Options::draw(sf::RenderWindow& window)
{
	window.draw(_window);
	window.draw(_debug_bg);
	window.draw(_turn_bg);
	window.draw(_info_bg);
	window.draw(_close_bg);
	window.draw(_debug_bt);
	window.draw(_turn_bt);
	window.draw(_info_bt);
	window.draw(_close_bt);
}

bool Options::click(const sf::Vector2i& click_pos, Field& field, const Checker::Color& current_color)
{
	if (click_pos.x / CHECKER_SIZE == DEBUG_BT_POS[0] && click_pos.y / CHECKER_SIZE == DEBUG_BT_POS[1])
	{
		if (_debug_mode)
		{
			_debug_mode = false;
			_debug_bg.setTextureRect(sf::IntRect(UNSELECTED_BT_TEXTURE[0] * CHECKER_SIZE, UNSELECTED_BT_TEXTURE[1] * CHECKER_SIZE, CHECKER_SIZE, CHECKER_SIZE));
			Log::debugDisable();
		}
		else
		{
			_debug_mode = true;
			_debug_bg.setTextureRect(sf::IntRect(SELECTED_BT_TEXTURE[0] * CHECKER_SIZE, SELECTED_BT_TEXTURE[1] * CHECKER_SIZE, CHECKER_SIZE, CHECKER_SIZE));
			Log::debugEnable();
		}
	}
	else if (click_pos.x / CHECKER_SIZE == TURN_BT_POS[0] && click_pos.y / CHECKER_SIZE == TURN_BT_POS[1])
	{
		if (_turn_mode)
		{
			_turn_mode = false;
			_turn_bg.setTextureRect(sf::IntRect(UNSELECTED_BT_TEXTURE[0] * CHECKER_SIZE, UNSELECTED_BT_TEXTURE[1] * CHECKER_SIZE, CHECKER_SIZE, CHECKER_SIZE));
			if (field.get_is_turned())
			{
				field.turn();
			}
		}
		else
		{
			_turn_mode = true;
			_turn_bg.setTextureRect(sf::IntRect(SELECTED_BT_TEXTURE[0] * CHECKER_SIZE, SELECTED_BT_TEXTURE[1] * CHECKER_SIZE, CHECKER_SIZE, CHECKER_SIZE));
			if (current_color == Checker::BLACK)
			{
				field.turn();
			}
		}
	}
	else if (click_pos.x / CHECKER_SIZE == INFO_BT_POS[0] && click_pos.y / CHECKER_SIZE == INFO_BT_POS[1])
	{
		std::thread new_window(Options::info_window);
		new_window.detach();
	}
	else if (click_pos.x / CHECKER_SIZE == CLOSE_BT_POS[0] && click_pos.y / CHECKER_SIZE == CLOSE_BT_POS[1])
	{
		return true;
	}
	return false;
}

void Options::info_window()
{
	sf::RenderWindow window(sf::VideoMode(500, 300), INFO_TITLE);
	window.setFramerateLimit(1);
	sf::Text text;
	sf::Font font;
	font.loadFromFile(FONTS_PATH + FONT_FILE + FONT_EXT);
	text.setFont(font);
	text.setString(INFO_TEXT);
	Log_d(D_INFO_OPEN);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				Log_d(D_INFO_CLOSE);
			}
		}
		window.clear();
		window.draw(text);
		window.display();
	}
}

bool Options::get_turn_mode() const
{
	return _turn_mode;
}