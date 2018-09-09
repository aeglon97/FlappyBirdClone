#pragma once

#include <sstream>
#include "SplashState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace Sonar
{
	SplashState::SplashState(GameDataRef data) : _data(data)
	{

	}

	void SplashState::Init()
	{
		this->_data->assets.LoadTexture("Splash-Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
		_background.setTexture(this->_data->assets.GetTexture("Splash-Background"));
	}

	void SplashState::HandleInput()
	{
		sf::Event event;
		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}
		}
	}

	void SplashState::Update(float dt)
	{
		if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			std::cout << "go to main menu" << std::endl;
		}
	}

	void SplashState::Draw(float dt)
	{
		this->_data->window.clear();
		this->_data->window.draw(_background);
		this->_data->window.display();
	}
}