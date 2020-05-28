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
	Log_d(D_FIELD_CREATED);
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

void Field::delete_moveLL(Field::MoveLL* moveLL)
{
	if (moveLL->next != nullptr)
	{
		delete_moveLL(moveLL->next);
	}
	delete moveLL;
}

Field::MoveLL* Field::get_moves(const Checker::Color& color, bool& eat)
{
	eat = false;
	MoveLL* mbegin = new MoveLL;
	MoveLL* mp = mbegin;
	mp->next = nullptr;
	MoveLL* ebegin = new MoveLL;
	MoveLL* ep = ebegin;
	ep->next = nullptr;
	for (int i = 0; i < FIELD_SIZE; i++)
	{
		for (int j = i % 2; j < FIELD_SIZE; j += 2)
		{
			if (_checkers[j][i] != nullptr && _checkers[j][i]->get_color() == color)
			{
				if (_checkers[j][i]->is_queen())
				{
					sf::Vector2i eaten(-1, -1);
					for (int k = 1; i + k < FIELD_SIZE && j + k < FIELD_SIZE; k++)
					{
						if (_checkers[j + k][i + k] == nullptr)
						{
							if (eaten == sf::Vector2i(-1, -1))
							{
								if (!eat)
								{
									mp->from = sf::Vector2i(j, i);
									mp->to = sf::Vector2i(j + k, i + k);
									mp->eaten = sf::Vector2i(-1, -1);
									mp->next = new MoveLL;
									mp = mp->next;
									mp->next = nullptr;
								}
							}
							else
							{
								eat = true;
								ep->from = sf::Vector2i(j, i);
								ep->to = sf::Vector2i(j + k, i + k);
								ep->eaten = eaten;
								ep->next = new MoveLL;
								ep = ep->next;
								ep->next = nullptr;
							}
						}
						else if (_checkers[j + k][i + k]->get_color() != color && eaten == sf::Vector2i(-1, -1))
						{
							eaten = sf::Vector2i(j + k, i + k);
						}
						else
						{
							break;
						}
					}
					eaten = sf::Vector2i(-1, -1);
					for (int k = 1; i + k < FIELD_SIZE && j - k >= 0; k++)
					{
						if (_checkers[j - k][i + k] == nullptr)
						{
							if (eaten == sf::Vector2i(-1, -1))
							{
								if (!eat)
								{
									mp->from = sf::Vector2i(j, i);
									mp->to = sf::Vector2i(j - k, i + k);
									mp->eaten = sf::Vector2i(-1, -1);
									mp->next = new MoveLL;
									mp = mp->next;
									mp->next = nullptr;
								}
							}
							else
							{
								eat = true;
								ep->from = sf::Vector2i(j, i);
								ep->to = sf::Vector2i(j - k, i + k);
								ep->eaten = eaten;
								ep->next = new MoveLL;
								ep = ep->next;
								ep->next = nullptr;
							}
						}
						else if (_checkers[j - k][i + k]->get_color() != color && eaten == sf::Vector2i(-1, -1))
						{
							eaten = sf::Vector2i(j - k, i + k);
						}
						else
						{
							break;
						}
					}
					eaten = sf::Vector2i(-1, -1);
					for (int k = 1; i - k >= 0 && j + k < FIELD_SIZE; k++)
					{
						if (_checkers[j + k][i - k] == nullptr)
						{
							if (eaten == sf::Vector2i(-1, -1))
							{
								if (!eat)
								{
									mp->from = sf::Vector2i(j, i);
									mp->to = sf::Vector2i(j + k, i - k);
									mp->eaten = sf::Vector2i(-1, -1);
									mp->next = new MoveLL;
									mp = mp->next;
									mp->next = nullptr;
								}
							}
							else
							{
								eat = true;
								ep->from = sf::Vector2i(j, i);
								ep->to = sf::Vector2i(j + k, i - k);
								ep->eaten = eaten;
								ep->next = new MoveLL;
								ep = ep->next;
								ep->next = nullptr;
							}
						}
						else if (_checkers[j + k][i - k]->get_color() != color && eaten == sf::Vector2i(-1, -1))
						{
							eaten = sf::Vector2i(j + k, i - k);
						}
						else
						{
							break;
						}
					}
					eaten = sf::Vector2i(-1, -1);
					for (int k = 1; i - k >= 0 && j - k >= 0; k++)
					{
						if (_checkers[j - k][i - k] == nullptr)
						{
							if (eaten == sf::Vector2i(-1, -1))
							{
								if (!eat)
								{
									mp->from = sf::Vector2i(j, i);
									mp->to = sf::Vector2i(j - k, i - k);
									mp->eaten = sf::Vector2i(-1, -1);
									mp->next = new MoveLL;
									mp = mp->next;
									mp->next = nullptr;
								}
							}
							else
							{
								eat = true;
								ep->from = sf::Vector2i(j, i);
								ep->to = sf::Vector2i(j - k, i - k);
								ep->eaten = eaten;
								ep->next = new MoveLL;
								ep = ep->next;
								ep->next = nullptr;
							}
						}
						else if (_checkers[j - k][i - k]->get_color() != color && eaten == sf::Vector2i(-1, -1))
						{
							eaten = sf::Vector2i(j - k, i - k);
						}
						else
						{
							break;
						}
					}
				}
				else
				{
					bool up = i + 2 < FIELD_SIZE, down = i - 2 >= 0, right = j + 2 < FIELD_SIZE, left = j - 2 >= 0;
					if (down)
					{
						if (left && _checkers[j - 1][i - 1] != nullptr && _checkers[j - 1][i - 1]->get_color() != color &&
							_checkers[j - 2][i - 2] == nullptr)
						{
							eat = true;
							ep->from = sf::Vector2i(j, i);
							ep->to = sf::Vector2i(j - 2, i - 2);
							ep->eaten = sf::Vector2i(j - 1, i - 1);
							ep->next = new MoveLL;
							ep = ep->next;
							ep->next = nullptr;
						}
						if (right && _checkers[j + 1][i - 1] != nullptr && _checkers[j + 1][i - 1]->get_color() != color &&
							_checkers[j + 2][i - 2] == nullptr)
						{
							eat = true;
							ep->from = sf::Vector2i(j, i);
							ep->to = sf::Vector2i(j + 2, i - 2);
							ep->eaten = sf::Vector2i(j + 1, i - 1);
							ep->next = new MoveLL;
							ep = ep->next;
							ep->next = nullptr;
						}
					}
					if (up)
					{
						if (left && _checkers[j - 1][i + 1] != nullptr && _checkers[j - 1][i + 1]->get_color() != color &&
							_checkers[j - 2][i + 2] == nullptr)
						{
							eat = true;
							ep->from = sf::Vector2i(j, i);
							ep->to = sf::Vector2i(j - 2, i + 2);
							ep->eaten = sf::Vector2i(j - 1, i + 1);
							ep->next = new MoveLL;
							ep = ep->next;
							ep->next = nullptr;
						}
						if (right && _checkers[j + 1][i + 1] != nullptr && _checkers[j + 1][i + 1]->get_color() != color &&
							_checkers[j + 2][i + 2] == nullptr)
						{
							eat = true;
							ep->from = sf::Vector2i(j, i);
							ep->to = sf::Vector2i(j + 2, i + 2);
							ep->eaten = sf::Vector2i(j + 1, i + 1);
							ep->next = new MoveLL;
							ep = ep->next;
							ep->next = nullptr;
						}
					}
					
					if (!eat)
					{
						int move = (color == Checker::WHITE ? 1 : -1);
						if (j - 1 >= 0 && _checkers[j - 1][i + move] == nullptr)
						{
							mp->from = sf::Vector2i(j, i);
							mp->to = sf::Vector2i(j - 1, i + move);
							mp->eaten = sf::Vector2i(-1, -1);
							mp->next = new MoveLL;
							mp = mp->next;
							mp->next = nullptr;
						}
						if (j + 1 < FIELD_SIZE && _checkers[j + 1][i + move] == nullptr)
						{
							mp->from = sf::Vector2i(j, i);
							mp->to = sf::Vector2i(j + 1, i + move);
							mp->eaten = sf::Vector2i(-1, -1);
							mp->next = new MoveLL;
							mp = mp->next;
							mp->next = nullptr;
						}
					}
				}
			}
		}
	}
	if (eat)
	{
		delete_moveLL(mbegin);
		for (MoveLL* p = ebegin; p->next != nullptr; p = p->next)
		{
			if (p->next->from.x < 0 || p->next->from.x >= FIELD_SIZE ||
				p->next->from.y < 0 || p->next->from.y >= FIELD_SIZE ||
				p->next->to.x < 0 || p->next->to.x >= FIELD_SIZE ||
				p->next->to.y < 0 || p->next->to.y >= FIELD_SIZE ||
				p->next->from == p->next->to)
			{
				MoveLL* next = p->next->next;
				delete p->next;
				p->next = next;
				if (p->next == nullptr)
				{
					break;
				}
			}
		}
		return ebegin;
	}
	else
	{
		delete_moveLL(ebegin);
		for (MoveLL* p = mbegin; p->next != nullptr; p = p->next)
		{
			if (p->next->from.x < 0 || p->next->from.x >= FIELD_SIZE ||
				p->next->from.y < 0 || p->next->from.y >= FIELD_SIZE ||
				p->next->to.x < 0 || p->next->to.x >= FIELD_SIZE ||
				p->next->to.y < 0 || p->next->to.y >= FIELD_SIZE ||
				p->next->from == p->next->to)
			{
				MoveLL* next = p->next->next;
				delete p->next;
				p->next = next;
				if (p->next == nullptr)
				{
					break;
				}
			}
		}
		return mbegin;
	}
}

bool Field::_can(const sf::Vector2i& from, const sf::Vector2i& to, Field::MoveLL* moves, sf::Vector2i& eaten) const
{
	for (MoveLL* p = moves; p != nullptr; p = p->next)
	{
		if (p->from == from && p->to == to)
		{
			eaten = p->eaten;
			return true;
		}
	}
	return false;
}

bool Field::click(sf::Vector2i position, Field::MoveLL* moves, const Checker::Color& color)
{
	static sf::Vector2i prev_position(0, 0);
	static Checker::Color prev_color = Checker::BLACK;
	position /= CHECKER_SIZE;
	position.y = FIELD_SIZE - position.y - 1;
	if (position.x < 0 || position.y < 0 ||
		position.x >= FIELD_SIZE || position.y >= FIELD_SIZE)
	{
		Log_w(W_CLICK_OUT_OF_WINDOW);
	}
	else
	{
		if (_checkers[position.x][position.y] == nullptr)
		{
			if (_selected != nullptr)
			{
				sf::Vector2i eaten;
				if ((color != prev_color || _selected->get_position() == prev_position) &&
					_can(_selected->get_position(), position, moves, eaten))
				{
					bool can = color != prev_color;
					if (!can)
					{
						for (MoveLL* p = moves; p != nullptr; p = p->next)
						{
							if (p->from == prev_position)
							{
								can = true;
								break;
							}
						}
					}

					if (can)
					{
						_checkers[position.x][position.y] = _checkers[_selected->get_position().x][_selected->get_position().y];
						_checkers[_selected->get_position().x][_selected->get_position().y] = nullptr;
						_selected->move(position);
						_selected->unselect();
						_selected = nullptr;
						if (eaten != sf::Vector2i(-1, -1))
						{
							delete _checkers[eaten.x][eaten.y];
							_checkers[eaten.x][eaten.y] = nullptr;
						}
						prev_color = color;
						prev_position = position;
						return true;
					}
				}
				else
				{
					_selected->unselect();
					_selected = nullptr;
				}
			}
		}
		else
		{
			if (_selected != nullptr)
			{
				_selected->unselect();
			}
			_checkers[position.x][position.y]->select();
			_selected = _checkers[position.x][position.y];
		}
	}
	return false;
}