#ifndef MAP_H
#define MAP_H


#include <cstdlib>
#include <ctime>
#include <vector>
#include <queue>


#include"object.h"
#include"Bot.h"
#include "Domain.h"
#include "sas.hpp"

//struct A { int a; };

class Map
{
public:
	Map(WorldSize*);
	~Map();

	std::queue<Pair<int>> bots;
	bool need_to_evolve(WorldSize* w) const;
	std::vector<std::vector<Object::ObjectType>> getPresentation();
	void evolve(WorldSize* w);
	void makeTurn(WorldSize* w);
private:

	int mFoodtCounter;
	int mPoisonCounter;

	std::queue<Pair<int>> mFoodSuitableCells;
	std::queue<Pair<int>> mPoisonSuitableCells;

	Bot::ActionType answer_for_bot(Object::ObjectType);
	std::vector<std::vector<Object*>> mField;

	void reloadBotsCoordinates();
	std::queue<Pair<int>> mBotsCoord;

	void clearBotsMemory(char aValue = 0);
	std::deque<Bot*> mOldBots;

	void createNewPlant(Object::ObjectType aType, std::queue<Pair<int>>& aSuitableCells, int aCount);
	void getSuitableCells(Object::ObjectType aType, std::queue<Pair<int>>& aContainer);
	bool checkNeighbours(Object::ObjectType aType, Pair<int> aCoord);


	Pair<int> findVoid();
	void setNewObject       (Object::ObjectType aType, Pair<int> aCoord);
	void setExictingObject  (Object* aObjectPtr, Pair<int> aCoord);
	void createObjects      (int aLim, Object::ObjectType aType);
	void regenerate(WorldSize* w);
};

#endif // !MAP_H           