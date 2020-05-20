    ////////////////////////////////////////
   //       Checkers by SnegirSoft       //
  //                                    //
 //  File: ResourceManager.cpp         //
////////////////////////////////////////

#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
	_field_texture = new sf::Texture();
	_field_texture->loadFromFile(TEXTURES_PATH + FIELD + TEXTURES_EXT);
	_checkers_texture = new sf::Texture();
	_checkers_texture->loadFromFile(TEXTURES_PATH + CHECKERS + TEXTURES_EXT);
}

ResourceManager::~ResourceManager()
{
	delete _field_texture;
	delete _checkers_texture;
}

const sf::Texture& ResourceManager::get_field_texture() const
{
	return *_field_texture;
}

const sf::Texture& ResourceManager::get_checkers_texture() const
{
	return *_checkers_texture;
}