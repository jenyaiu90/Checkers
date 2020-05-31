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

	_logo_texture = new sf::Texture();
	if (_logo_texture->loadFromFile(TEXTURES_PATH + LOGO_FILE + TEXTURES_EXT))
	{
		Log_d(D_FILE_LOADED + TEXTURES_PATH + LOGO_FILE + TEXTURES_EXT);
	}
	else
	{
		Log_w(E_NO_FILE + TEXTURES_PATH + LOGO_FILE + TEXTURES_EXT);
	}

	_options_window_texture = new sf::Texture();
	if (_options_window_texture->loadFromFile(TEXTURES_PATH + OPTIONS_WINDOW_FILE + TEXTURES_EXT))
	{
		Log_d(D_FILE_LOADED + TEXTURES_PATH + OPTIONS_WINDOW_FILE + TEXTURES_EXT);
	}
	else
	{
		Log_e(E_NO_FILE + TEXTURES_PATH + OPTIONS_WINDOW_FILE + TEXTURES_EXT);
	}

	_buttons_texture = new sf::Texture();
	if (_buttons_texture->loadFromFile(TEXTURES_PATH + BUTTONS_FILE + TEXTURES_EXT))
	{
		Log_d(D_FILE_LOADED + TEXTURES_PATH + BUTTONS_FILE + TEXTURES_EXT);
	}
	else
	{
		Log_e(E_NO_FILE + TEXTURES_PATH + BUTTONS_FILE + TEXTURES_EXT);
	}
}

ResourceManager::~ResourceManager()
{
	delete _field_texture;
	delete _checkers_texture;
	delete _logo_texture;
	delete _options_window_texture;
	delete _buttons_texture;
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

const sf::Texture& ResourceManager::get_logo_texture() const
{
	return *_logo_texture;
}

const sf::Texture& ResourceManager::get_options_window_texture() const
{
	return *_options_window_texture;
}

const sf::Texture& ResourceManager::get_buttons_texture() const
{
	return *_buttons_texture;
}