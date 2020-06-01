    ////////////////////////////////////////
   //       Checkers by SnegirSoft       //
  //                                    //
 //  File: Checker.h                   //
////////////////////////////////////////

#include "Checker.h"
#include <thread>
#include <mutex>
#include <SFML/System.hpp>

Checker::Checker(const Color& color, sf::Vector2i position, const sf::Texture& texture)
{
	_color = color;
	_is_queen = false;
	_is_selected = false;
	_is_turned = false;
	_sprite.setTexture(texture);
	_sprite.setTextureRect(sf::IntRect(
		_color == WHITE ? WHITE_TEXTURE * CHECKER_SIZE : BLACK_TEXTURE * CHECKER_SIZE,
		0, CHECKER_SIZE, CHECKER_SIZE));
	_position = position;
	position.y = FIELD_SIZE - 1 - position.y;
	_sprite.setPosition((sf::Vector2f)position * (float)CHECKER_SIZE);
}

void Checker::move_in_background(sf::Vector2i new_position, const bool& an)
{
	static sf::Mutex mtx;
	_position = new_position;
	new_position.y = FIELD_SIZE - 1 - new_position.y;
	if (_is_turned)
	{
		new_position.x = FIELD_SIZE - 1 - new_position.x;
		new_position.y = FIELD_SIZE - 1 - new_position.y;
	}
	mtx.lock();
	if (an)
	{
		sf::Vector2f delta = (sf::Vector2f)new_position - _sprite.getPosition() / (float)CHECKER_SIZE;
		delta /= 25.f;
		delta *= (float)CHECKER_SIZE;
		sf::Clock clock;

		for (int i = 0; i < 25; i++)
		{
			while (clock.getElapsedTime().asMilliseconds() < 40);
			clock.restart();
			_sprite.setPosition(_sprite.getPosition() + delta);
		}
	}
	_sprite.setPosition((sf::Vector2f)new_position * (float)CHECKER_SIZE);
	if (!_is_queen && _position.y == (_color == WHITE ? FIELD_SIZE - 1 : 0))
	{
		_is_queen = true;
		sf::IntRect rect = _sprite.getTextureRect();
		rect.left = (_color == WHITE ? WHITE_Q_TEXTURE : BLACK_Q_TEXTURE) * CHECKER_SIZE;
		_sprite.setTextureRect(rect);
	}
	mtx.unlock();
}

void Checker::move(const sf::Vector2i& new_position, const bool& an)
{
	std::thread move_thread([new_position, an](Checker* checker)
	{
		checker->move_in_background(new_position, an);
	}, this);
	move_thread.detach();

	Log_d(D_CHECKER_MOVE + "(" + std::to_string(new_position.x) + "; " + std::to_string(new_position.y) + ")");
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

void Checker::turn()
{
	_is_turned = !_is_turned;
	_sprite.setPosition((FIELD_SIZE - 1 - _sprite.getPosition().x / CHECKER_SIZE) * CHECKER_SIZE,
		(FIELD_SIZE - 1 - _sprite.getPosition().y / CHECKER_SIZE) * CHECKER_SIZE);
}