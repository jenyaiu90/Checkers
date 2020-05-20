    ////////////////////////////////////////
   //       Checkers by SnegirSoft       //
  //                                    //
 //  File: Field.h                     //
////////////////////////////////////////

#pragma once

#include "Checker.h"

//Класс игрового поля
class Field
{
protected:
	Checker* _checkers[FIELD_SIZE][FIELD_SIZE];
	Checker* _selected;
	sf::Sprite _sprite;
public:
	Field(const ResourceManager& rm);
	~Field();

	void draw(sf::RenderWindow& window);
};
