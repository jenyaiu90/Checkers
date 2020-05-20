    ////////////////////////////////////////
   //       Checkers by SnegirSoft       //
  //                                    //
 //  File: Checker.h                   //
////////////////////////////////////////

#include "Checker.h"

Checker::Checker(const Color& color, const sf::Vector2i& position, const sf::Texture& texture)
{
	_color = color;
	_is_queen = false;
	_is_selected = false;
	_sprite.setTexture(texture);
	_sprite.setTextureRect(sf::IntRect(
		_color == WHITE ? WHITE_TEXTURE * CHECKER_SIZE : BLACK_TEXTURE * CHECKER_SIZE,
		0, CHECKER_SIZE, CHECKER_SIZE));
	move(position);
}

void Checker::move(const sf::Vector2i& new_position)
{
	_position = new_position;
	_sprite.setPosition(_position.x * CHECKER_SIZE, (FIELD_SIZE - _position.y - 1) * CHECKER_SIZE);
}

void Checker::draw(sf::RenderWindow& window)
{
	window.draw(_sprite);
}

void Checker::select()
{
	_is_selected = true;
	sf::IntRect rect = _sprite.getTextureRect();
	rect.top = SELECTED_TEXTURE * CHECKER_SIZE;
	_sprite.setTextureRect(rect);
}

void Checker::unselect()
{
	_is_selected = false;
	sf::IntRect rect = _sprite.getTextureRect();
	rect.top = UNSELECTED_TEXTURE * CHECKER_SIZE;
	_sprite.setTextureRect(rect);
}