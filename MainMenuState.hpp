#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include <optional>

namespace Ldman
{
	class MainMenuState : public State
	{
	public:
		MainMenuState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		std::optional<sf::Sprite> _background;
		std::optional<sf::Sprite> _title;
		std::optional<sf::Sprite> _playButton;
	};
}





