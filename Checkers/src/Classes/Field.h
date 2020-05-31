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
public:
	struct MoveLL
	{
		sf::Vector2i from;
		sf::Vector2i to;
		sf::Vector2i eaten;
		MoveLL* next;
	};
protected:
	Checker* _checkers[FIELD_SIZE][FIELD_SIZE];
	Checker* _selected;
	sf::Sprite _sprite;
	bool _is_turned;

	bool _can(const sf::Vector2i& from, const sf::Vector2i& to, MoveLL* moves, sf::Vector2i& eaten) const;
public:
	Field(const ResourceManager& rm);
	~Field();

	static void delete_moveLL(MoveLL* moveLL);
	MoveLL* get_moves(const Checker::Color& color, bool& eat);

	void draw(sf::RenderWindow& window);
	bool click(sf::Vector2i position, MoveLL* moves, const Checker::Color& color, bool& options);
	void turn();
	bool get_is_turned();
};
