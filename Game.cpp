#include "Game.hpp"
#include "SplashState.hpp"

namespace Ldman {
	Game::Game(int width, int height, std::string title) {
		_data->window.create(sf::VideoMode({ static_cast<unsigned int>(width), static_cast<unsigned int>(height) }), title, sf::Style::Close | sf::Style::Titlebar);

		_data->machine.AddState(StateRef(new SplashState(this->_data)));

		this->Run();
	}

	void Game::Run() {
		float newTime, frameTime, interpolation;

		float currentTime = this->_clock.getElapsedTime().asSeconds(); //the amount of time that has occured since the clock started

		float accumulator = 0.0f;

		while (this->_data->window.isOpen()) 
		{
			this->_data->machine.ProcessStateChanges();

			newTime = this->_clock.getElapsedTime().asSeconds();

			frameTime = newTime - currentTime;

			if (frameTime > 0.25f) 
			{
				frameTime = 0.25f;
			}

			currentTime = newTime;
			accumulator += frameTime; //total of all the frame times

			while (accumulator >= dt)
			{
				this->_data->machine.GetActiveState()->HandleInput();
				this->_data->machine.GetActiveState()->Update(dt);

				accumulator -= dt;
			}
			interpolation = accumulator / dt;
			this->_data->machine.GetActiveState()->Draw(interpolation);
		}
	}
}