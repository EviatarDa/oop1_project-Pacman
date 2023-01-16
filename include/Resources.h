#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Resources {
public:
	~Resources() = default;
	static Resources& instance();
	void loadfromfile();
	sf::Texture gettexture(int);
	sf::SoundBuffer getsong();
private:
	Resources() =default;
	Resources(const Resources&)= delete;
	Resources operator=(const Resources&) = delete;

	sf::Texture m_Textures[10];
	sf::SoundBuffer m_song;


};
