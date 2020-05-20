    ////////////////////////////////////////
   //       Checkers by SnegirSoft       //
  //                                    //
 //  File: ResourceManager.cpp         //
////////////////////////////////////////

#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
	_field_texture = new sf::Texture();
	if (_field_texture->loadFromFile(TEXTURES_PATH + FIELD_FILE + TEXTURES_EXT))
	{
		Log_d(D_FILE_LOADED + TEXTURES_PATH + FIELD_FILE + TEXTURES_EXT);
	}
	else
	{
		Log_e(E_NO_FILE + TEXTURES_PATH + FIELD_FILE + TEXTURES_EXT);
	}
	_checkers_texture = new sf::Texture();
	if (_checkers_texture->loadFromFile(TEXTURES_PATH + CHECKERS_FILE + TEXTURES_EXT))
	{
		Log_d(D_FILE_LOADED + TEXTURES_PATH + CHECKERS_FILE + TEXTURES_EXT);
	}
	else
	{
		Log_e(E_NO_FILE + TEXTURES_PATH + CHECKERS_FILE + TEXTURES_EXT);
	}
}

ResourceManager::~ResourceManager()
{
	delete _field_texture;
	delete _checkers_texture;
	Log_d(D_R_MANAGER_UNLOADED);
}

const sf::Texture& ResourceManager::get_field_texture() const
{
	return *_field_texture;
}

const sf::Texture& ResourceManager::get_checkers_texture() const
{
	return *_checkers_texture;
}