
#ifndef GAME
#define GAME

#include<iostream>
#include<SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "window.hpp"
#include "world.hpp"
#include "snake.hpp"

using MessageContainer = std::vector<std::string>;

class Textbox {

public:
	Textbox();
	Textbox(int l_visible, int l_charSize, int l_width, sf::Vector2f l_screenPos);
	~Textbox();

	void Setup(int l_visible, int l_charSize, int l_width, sf::Vector2f l_screenPos);
	void Add(std::string l_message);
	void Clear();
	void Update();
	void Render(sf::RenderWindow& l_wind);

private:
	MessageContainer m_message;
	int m_numVisible;

	sf::RectangleShape m_backdrop;
	sf::Font m_font;
	sf::Text m_content;

};



class Game {
public:
	Game();
	~Game();
	void HandleInput();
	void Update();
	void Render();
	Window* GetWindow();
	sf::Time GetElapsed();
	void RestartClock();

private:
	Window m_window;
	World m_world;
	Snake m_snake;
	sf::Clock m_clock;
	sf::Time m_elapsed;
	Textbox m_textbox;

};




#endif
