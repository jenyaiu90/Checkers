    ////////////////////////////////////////
   //       Checkers by SnegirSoft       //
  //                                    //
 //  File: Checker.h                   //
////////////////////////////////////////

#pragma once

#include "../System/ResourceManager.h"

//Класс шашки
class Checker
{
public:
	//Цвет шашки
	enum Color
	{
		WHITE, //Белый
		BLACK //Чёрный
	};
protected:
	Color _color; //Цвет шашки
	bool _is_queen; //Является ли дамкой
	bool _is_selected; //Выделена ли
	sf::Vector2i _position; //Координаты на доске
	sf::Sprite _sprite; //Спрайт
public:
	Checker(const Color& color, const sf::Vector2i& position, const sf::Texture& texture);

	void move(const sf::Vector2i& new_position); //Подвинуть шашку
	void draw(sf::RenderWindow& window); //Отрисовать шашку
	void select(); //Выделить
	void unselect(); //Снять выделение
};
