#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>

#include <vector>
#include "Object.h"
#include "sas.hpp"
#include <fstream>

class Gui
{

public:
	enum EventType
	{
		NUN = 0,
		SWITCH_DRAW_MODE = 1,  //c
		SWITCH_PAUSE = 2,      //z
		INCREASE_SPEED = 3,
		DECREASE_SPEED = 4,
		STANDART_PAUSE = 5,
		DRAW_GRAPH=6           //g
	};

	Gui(int x, int y);
	~Gui();
	std::vector<Gui::EventType> get_events();
	void draw_graph(sf::VertexArray asd);
	void draw(std::vector<std::vector<Object::ObjectType>> result,WorldSize* w);
	sf::VertexArray graph();
	std::ifstream fin;

private:
	
	sf::RenderWindow mWindow;
	sf::Text mText;
};


#endif // !GUI_H


