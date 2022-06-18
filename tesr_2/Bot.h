#ifndef BOT_H
#define BOT_H


#include "Object.h"
#include "direction.h"

#include <set>
#include <vector>
#include <iostream>

class Bot :public Object
{
public:

	enum ActionType
	{
		NUN = 0,
		VOID = 1,
		MOVE = 2,
		EAT = 3,
		LOOK = 4,
		MAKE = 5
	};

	Bot();
	Bot(const Bot& aOther);
	virtual ~Bot();

	char getHealph() const;
	const Direction& getDirection() const;

	void feed(float aValue);
	void poison(float aValue);
	bool aging();
	void test_go();
	Bot::ActionType makeAction(Object::ObjectType aType);
	void evolve(int aValue);
	void reset();

private:
	enum Comands
	{
		BOT_GO = 11,
		BOT_EAT = 12,
		BOT_MAKE = 13,
		BOT_LOOK = 14,
		BOT_TURN_RIGHT = 15,
		BOT_TURN_LEFT = 16,

	};

	
	char mHealph;
	Direction mDirection;

	char mProgramPtr;
	std::vector<char> mProgram;

	char generateComand() const;        //
	void shiftProgramPtr(int aValue);   //
	
};

#endif // !BOT_H