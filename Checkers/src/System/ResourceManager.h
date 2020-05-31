    ////////////////////////////////////////
   //       Checkers by SnegirSoft       //
  //                                    //
 //  File: ResourceManager.h           //
////////////////////////////////////////

#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Log.h"

class ResourceManager
{
protected:
	sf::Texture* _field_texture;
	sf::Texture* _checkers_texture;
	sf::Texture* _logo_texture;
	sf::Texture* _options_window_texture;
	sf::Texture* _buttons_texture;
public:
	ResourceManager();
	~ResourceManager();
	
	const sf::Texture& get_field_texture() const;
	const sf::Texture& get_checkers_texture() const;
	const sf::Texture& get_logo_texture() const;
	const sf::Texture& get_options_window_texture() const;
	const sf::Texture& get_buttons_texture() const;

};
