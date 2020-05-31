    ////////////////////////////////////////
   //       Checkers by SnegirSoft       //
  //                                    //
 //  File: Options.h                   //
////////////////////////////////////////

#pragma once

#include "../System/ResourceManager.h"
#include "Field.h"

class Options
{
protected:
	bool _debug_mode;
	bool _turn_mode;

	sf::Sprite _window;
	sf::Sprite _debug_bg, _turn_bg, _close_bg, _info_bg;
	sf::Sprite _debug_bt, _turn_bt, _close_bt, _info_bt;
public:
	Options(ResourceManager& rm);

	void draw(sf::RenderWindow& window);
	bool click(const sf::Vector2i& click_pos, Field& field, const Checker::Color& current_color);
	static void info_window();

	bool get_turn_mode() const;
};
