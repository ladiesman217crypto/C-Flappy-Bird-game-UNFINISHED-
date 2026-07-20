#include <sstream>
#include "SplashState.hpp"
#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace Ldman
{
	SplashState::SplashState(GameDataRef data) : _data(data)
	{

	}

	void SplashState::Init() //Loads the texture using asset manager and sets the texture to the background sprite
	{
		_data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);

		_background.emplace(this->_data->assets.GetTexture("Splash State Background"));
	}

	void SplashState::HandleInput()
	{
		while (const std::optional event = _data->window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				_data->window.close();
			}
		}
	}

	void SplashState::Update(float dt) //We check how many seconds have passed
	{
		if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
		}
	}

	void SplashState::Draw(float dt)
	{
		_data->window.clear();

		if (_background)
		{
			_data->window.draw(*_background);
		}
		
		_data->window.display();
	}
}















