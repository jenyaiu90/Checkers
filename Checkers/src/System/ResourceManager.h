    ////////////////////////////////////////
   //       Checkers by SnegirSoft       //
  //                                    //
 //  File: ResourceManager.h           //
////////////////////////////////////////

#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "../Constants.h"

class ResourceManager
{
protected:
	sf::Texture* _field_texture;
	sf::Texture* _checkers_texture;
public:
	ResourceManager();
	~ResourceManager();

	const sf::Texture& get_field_texture() const;
	const sf::Texture& get_checkers_texture() const;
};
