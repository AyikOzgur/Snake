

#ifndef WINDOW
#define WINDOW

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>



class Window
{
public:
	Window();
	Window(const std::string &l_title, const sf::Vector2u  &l_size);
	~Window();

	void BeginDraw();
	void EndDraw();
	void Update();

	bool IsDone();
	bool IsFullscreen();
	sf::Vector2u GetWindowSize();

	void ToggleFullscreen();
	void Draw(sf::Drawable& l_drawable);
	sf::RenderWindow m_window;

private:
	void Setup(const std::string &l_title, const sf::Vector2u &l_size);
	void Destroy();
	void Create();

	sf::Vector2u m_windowSize;
	std::string m_windowTitle;
	bool m_isDone;
	bool m_isFullscreen;

};



#endif
