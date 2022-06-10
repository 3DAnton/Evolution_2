#include "Event.h"
#include <SFML/Graphics.hpp>
#include <iostream>


//Pair<int> Event::mouse(int x, y)
//{
//	sf::Vector2i q;
//	q = sf::Mouse::getPosition();
//	int x2=q[0], y2=q[1];
//	return Pair<int>(x + x2, y + y2);
//} 

Event::Event() {};

Pair<int> Event::mouse()
{
	sf::Vector2i q;
	q = sf::Mouse::getPosition();
	int x2=q.x, y2=q.y;
	Pair<int> res;
	res.x = x2;
	res.y = y2;

	return res;
}

Event::~Event() {};