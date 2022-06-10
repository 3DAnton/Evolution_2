#ifndef DIRECTION_H
#define DIRECTION_H

#include <cstdlib>

#include "domain.h"

/*
	A class that implements the direction of the bot.

	Directions are:
	UP_RIGHT	=	0
	RIGHT		=	1
	DOWN_RIGHT	=	2
	DOWN_LEFT	=	3
	LEFT		=	4
	UP_LEFT		=	5
*/
struct Direction
{
public:
	Direction();
	
	Direction(char aDirValue);


	Direction& operator++();
	Direction operator++(int);

	Direction& operator--();
	Direction operator--(int);

	void reset();
	
	Pair<int> shiftPair(const Pair<int>& aPair) const;

private:
	char mValue;
};

//--------------------------------------------------------------------------------

#endif // DIRECTION_H