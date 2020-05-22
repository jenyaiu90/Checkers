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
	Log_d(D_CHECKER_MOVE + "(" + std::to_string(new_position.x) + "; " + std::to_string(new_position.y) + ")");

	if (!_is_queen && _position.y == (_color == WHITE ? FIELD_SIZE - 1 : 0))
	{
		_is_queen = true;
		sf::IntRect rect = _sprite.getTextureRect();
		rect.left = (_color == WHITE ? WHITE_Q_TEXTURE : BLACK_Q_TEXTURE) * CHECKER_SIZE;
		_sprite.setTextureRect(rect);
	}
}

void Checker::draw(sf::RenderWindow& window) const
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

sf::Vector2i Checker::get_position() const
{
	return _position;
}

Checker::Color Checker::get_color() const
{
	return _color;
}

bool Checker::is_queen() const
{
	return _is_queen;
}