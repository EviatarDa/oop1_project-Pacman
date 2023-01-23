#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string.h>

enum Button { PLAY, HELP, EXIT, VIDEO_PLAY, BACK };

enum Title { TITLE, HELLO, WANNA_PLAY, LETS_GO, TITLE_PACMAN, TITLE_DEAMONS };

enum Instructions { SHIR, EVIATAR1, EVIATAR2, SHIR_DROP, EVIATAR_DROP, OH_NO, GAME_RULES };

enum Object { PACMAN, DEAMON_ORANGE, DEAMON_PINK, DEAMON_RED, DEAMON_AZURE, KEY, WALL, DOOR, COOKIE, SUPER_PRESENT, ADD_LIFE, FREEZE, ADD_TIME };

enum Direction { Up, Down, Right, Left, Stay };

enum ToolBarWord { LIFE, SCORE, LEVEL, TIME, KEYCOUNTER };

enum Sound { SONG, CLICK, MINUS_LIFE, EAT, GAME_OVER};


const int BUTTONS = 5;
const int TITLE_OBJECTS = 6;
const int INSTRUCTIONS = 7;
const int GAME_OBJECTS = 13;
const int TOOL_BAR = 5;
const int SOUNDS = 5;

class Resources 
{

public:
	Resources();
	~Resources() = default;
	static Resources& instance();
	void LoadFromFile();
	sf::Texture& GetButton(Button);
	sf::Texture& GetTitle(Title);
	sf::Texture& GetInstruction(Instructions);
	sf::Texture& GetGameObject(Object);
	sf::SoundBuffer& GetSound(Sound);
	sf::Font& GetFont();

private:
	
	Resources(const Resources&)= delete;
	Resources operator=(const Resources&) = delete;
	sf::Font m_font;
	sf::SoundBuffer m_Sounds[SOUNDS];
	sf::Texture m_ButtonTextures[BUTTONS];
	sf::Texture m_TitleTextures[TITLE_OBJECTS];
	sf::Texture m_InstructionsTextures[INSTRUCTIONS];
	sf::Texture m_GameObjectTextures[GAME_OBJECTS];

	std::string m_ButtonFiles[BUTTONS] = { "Play.png", "Help.png", "Exit.png" , "VideoPlay.png" , "Back.png" };
	std::string m_TitleFiles[TITLE_OBJECTS] = { "title.png", "Hello.png", "WannaPlay.png", "LetsGo.png" , "Pacman-Title.png" , "Deamons-Title.png" };
	std::string m_InstructionFiles[INSTRUCTIONS] = { "Shir.png" , "Eviatar1.png", "Eviatar2.png", "ShirDrop.png" , "EviatarDrop.png", "OhNo.png", "GameRules.png" };
	std::string m_GameObjectFiles[GAME_OBJECTS] = { "Pacman.png", "Deamon_Orange.png" ,"Deamon_Pink.png","Deamon_Red.png","Deamon_Azure.png",
													"Key.png", "Wall.png", "Door.png", "Cookie.png", "SuperPresent.png", "AddLife.png", "Freeze.png", "AddTime.png" };
	std::string m_SoundFiles[SOUNDS] = { "Song.ogg", "Click.ogg", "MinusLife.ogg", "Eat.ogg", "GameOver.ogg"};


};