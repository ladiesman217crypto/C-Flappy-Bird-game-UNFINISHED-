#include "inputManager.hpp"

namespace Ldman {
	bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button,
		sf::RenderWindow &window) 
	{
		//Checking the mouse clicks

		if (sf::Mouse::isButtonPressed(button)) {

			sf::FloatRect bounds = object.getGlobalBounds();


			//Get the mouse position relative to the window and convert it to float coordinates
			sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
			

			//Check if mouse's coordinates gets in sprite bounds
			if (bounds.contains(mousePos)) {
				return true;
			}

		}

		return false;

	}


	sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow &window) {
		return sf::Mouse::getPosition(window);
	}
}