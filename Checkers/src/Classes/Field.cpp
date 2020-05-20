    ////////////////////////////////////////
   //       Checkers by SnegirSoft       //
  //                                    //
 //  File: Field.cpp                   //
////////////////////////////////////////

#include "Field.h"

Field::Field(const ResourceManager& rm)
{
	_sprite.setTexture(rm.get_field_texture());

	for (int i = 0; i < CHECKER_ROWS; i++)
	{
		for (int j = i % 2; j < FIELD_SIZE; j += 2)
		{
			_checkers[j][i] = new Checker(Checker::WHITE, sf::Vector2i(j, i), rm.get_checkers_texture());
		}
	}

	for (int i = FIELD_SIZE - 1; i >= FIELD_SIZE - CHECKER_ROWS; i--)
	{
		for (int j = i % 2; j < FIELD_SIZE; j += 2)
		{
			_checkers[j][i] = new Checker(Checker::BLACK, sf::Vector2i(j, i), rm.get_checkers_texture());
		}
	}
}

Field::~Field()
{
	for (int i = 0; i < FIELD_SIZE; i++)
	{
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			if (_checkers[i][j] != nullptr)
			{
				delete _checkers[i][j];
			}
		}
	}
}

void Field::draw(sf::RenderWindow& window)
{
	window.draw(_sprite);
	for (int i = 0; i < FIELD_SIZE; i++)
	{
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			if (_checkers[i][j] != nullptr)
			{
				_checkers[i][j]->draw(window);
			}
		}
	}
}