#include "AssetManager.hpp"

namespace Ldman {
	void AssetManager::LoadTexture(std::string name, std::string fileName) {
		sf::Texture tex;

		if (tex.loadFromFile( fileName )) { //if we successfully load the file we passed in
			this->_textures[name] = tex; //then we can add it to the map of textures that we already have
		}
	}

	sf::Texture &AssetManager::GetTexture(std::string name) {
		return this->_textures.at(name);
	}


	void AssetManager::LoadFont(std::string name, std::string fileName) {
		sf::Font font;

		if ( font.openFromFile(fileName)) { 
			this->_fonts[name] = font; 
		}
	}

	sf::Font &AssetManager::GetFont(std::string name) {
		return this->_fonts.at(name);
	}
}



