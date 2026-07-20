#include <sstream>
#include "GameState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace Ldman
{
	GameState::GameState(GameDataRef data) : _data(data)
	{

	}

	void GameState::Init() //Loads the texture using asset manager and sets the texture to the background sprite
	{
		std::cout << "Game State" << std::endl;
		
		_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);

		_data->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH);
		_data->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
		
		pipe = new Pipe(_data);

		_background.emplace(this->_data->assets.GetTexture("Game Background"));
	}

	void GameState::HandleInput()
	{
		while (const std::optional event = _data->window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				_data->window.close();
			}
		}
	}

	void GameState::Update(float dt) //We check how many seconds have passed
	{
		
	}

	void GameState::Draw(float dt)
	{
		_data->window.clear();

		if (_background)
		{
			_data->window.draw(*_background);
		}

		pipe->DrawPipes();

		_data->window.display();

		
	}
}















