#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "inputManager.hpp"


namespace Ldman {
	struct GameData {
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
	};

	typedef std::shared_ptr<GameData> GameDataRef; 

	class Game {
	public:
		Game(int width, int height, std::string title);  //width, height of our screen. And name of our application

	private:
		const float dt = 1.0f / 60.0f; //frane rate
		sf::Clock _clock; //its required to handle frame rate

		GameDataRef _data = std::make_shared<GameData>();

		void Run(); //method that will be called when we start a game
	};
}


