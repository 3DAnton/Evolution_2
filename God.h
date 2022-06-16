#ifndef GOD_H
#define GOD_H

#include "Gui.h"
#include "Map.h"
#include "Event.h"
#include "sas.hpp"

class God
{
public:
	God(WorldSize*);
	~God();

	
	void run_2(WorldSize*);
	void run(WorldSize*);
private:
	Map mWorld;
	Gui mWindow;
	WorldSize w;

};

#endif // GOD_H




