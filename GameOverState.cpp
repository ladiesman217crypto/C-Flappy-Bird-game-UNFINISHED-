#include <sstream>
#include "GameOverState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace Ldman
{
	GameOverState::GameOverState(GameDataRef data) : _data(data)
	{

	}

	void GameOverState::Init() //Loads the texture using asset manager and sets the texture to the background sprite
	{
		_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);

		_background.emplace(this->_data->assets.GetTexture("Game Over Background"));
	}

	void GameOverState::HandleInput()
	{
		while (const std::optional event = _data->window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				_data->window.close();
			}
		}
	}

	void GameOverState::Update(float dt) //We check how many seconds have passed
	{

	}

	void GameOverState::Draw(float dt)
	{
		_data->window.clear();

		if (_background)
		{
			_data->window.draw(*_background);
		}

		_data->window.display();
	}
}















