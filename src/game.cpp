/*
 * game.cpp
 *
 *  Created on: Feb 21, 2023
 *      Author: ozgur
 */



/*
 * Game.cpp
 *
 *  Created on: Feb 20, 2023
 *      Author: ozgur
 */

#include "game.hpp"


Game::Game(): m_window("Snake",sf::Vector2u(800,600)),
m_world(sf::Vector2u(800,600)),
m_snake(m_world.GetBlockSize()),
m_textbox(5,14,350,sf::Vector2f(255,0))
{
	// Setting up class members.
}

Game::~Game(){}

void Game::Update(){
	m_window.Update(); // Update window events.
	float timestep = (1.0f / m_snake.GetSpeed());
	if(m_elapsed.asSeconds() >= timestep){
		m_snake.Tick();
		m_world.Update(m_snake);
		m_elapsed -= sf::seconds(timestep);
		if(m_snake.HasLost()){m_snake.Reset();
		}
	}

	m_textbox.Clear();
	// Setting up class members.
	m_textbox.Add("\t\t\t Game parameters  ");

	m_textbox.Add("health : " + std::to_string(m_snake.m_lives));
	m_textbox.Add("Score : "+ std::to_string(m_snake.m_score));

}



void Game::Render()
{
	m_window.BeginDraw(); // Clear.
	m_world.Render(m_window.m_window);
	m_snake.Render(m_window.m_window);
	m_textbox.Render(m_window.m_window);
	m_window.EndDraw(); // Display.
}

void Game::HandleInput()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
	&& m_snake.GetDirection() != Direction::Down)
	{
	m_snake.SetDirection(Direction::Up);
	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
	&& m_snake.GetDirection() != Direction::Up)
	{
	m_snake.SetDirection(Direction::Down);
	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
	&& m_snake.GetDirection() != Direction::Right)
	{
	m_snake.SetDirection(Direction::Left);
	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
	&& m_snake.GetDirection() != Direction::Left)
	{
	m_snake.SetDirection(Direction::Right);
	}
}


Window* Game::GetWindow()
{
	return &m_window;
}


sf::Time Game::GetElapsed(){ return m_elapsed; }
void Game::RestartClock(){ m_elapsed = m_clock.restart(); }


////////////////////////////// Textbox ///////////////////////////////////

Textbox::Textbox(){
	Setup(5,9,200,sf::Vector2f(0,0));
}

Textbox::Textbox(int l_visible, int l_charSize, int l_width, sf::Vector2f l_screenPos){
	Setup(l_visible,l_charSize,l_width,l_screenPos);
}

Textbox::~Textbox(){Clear();}

void Textbox::Setup(int l_visible, int l_charSize, int l_width, sf::Vector2f l_screenPos){

	m_numVisible = l_visible;
	sf::Vector2f l_offset(2.0f,2.0f);
	m_font.loadFromFile("./Arial.ttf");

	m_content.setFont(m_font);
	m_content.setString("");
	m_content.setCharacterSize(l_charSize);
	m_content.setColor(sf::Color::Green);
	m_content.setPosition(l_screenPos+l_offset);

	m_backdrop.setSize(sf::Vector2f(l_width,(l_visible * (l_charSize * 1.2f))));
	m_backdrop.setFillColor(sf::Color(90,90,90,90));
	m_backdrop.setPosition(l_screenPos);

}

void Textbox::Add(std::string l_message){
	m_message.push_back(l_message);
	if(m_message.size()<6){return;}
	m_message.erase(m_message.begin());

}

void Textbox::Clear(){
	m_message.clear();
}

void Textbox::Update(){

	Clear();
	// Setting up class members.
	Add("\t\t\t Game parameters  ");

	Add("health : " + std::to_string(5));
	Add("Score : "+ std::to_string(5));

}

void Textbox::Render(sf::RenderWindow& l_wind){

	std::string l_content;

	for(auto &itr : m_message)
	{
		l_content.append(itr+"\n");

	}

	if(l_content != ""){

		m_content.setString(l_content);
		l_wind.draw(m_backdrop);
		l_wind.draw(m_content);
	}
}

