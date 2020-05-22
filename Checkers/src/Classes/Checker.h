    ////////////////////////////////////////
   //       Checkers by SnegirSoft       //
  //                                    //
 //  File: Checker.h                   //
////////////////////////////////////////

#pragma once

#include "../System/ResourceManager.h"

class Checker
{
public:
	enum Color
	{
		WHITE,
		BLACK
	};
protected:
	Color _color;
	bool _is_queen;
	bool _is_selected;
	sf::Vector2i _position;
	sf::Sprite _sprite;
public:
	Checker(const Color& color, const sf::Vector2i& position, const sf::Texture& texture);

	void move(const sf::Vector2i& new_position);
	void draw(sf::RenderWindow& window) const;
	void select();
	void unselect();
	sf::Vector2i get_position() const;
	Color get_color() const;
	bool is_queen() const;
};
