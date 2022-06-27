#ifndef GOD_H
#define GOD_H

#include "Gui.h"
#include "Map.h"
#include "Event.h"
#include "sas.hpp"
#include <fstream>

class God
{
public:
	God(WorldSize*);
	~God();

	
	void run_2(WorldSize*);
	void run(WorldSize*);
	std::ofstream fout;

private:
	Map mWorld;
	Gui mWindow;
	WorldSize w;

};

#endif // GOD_H




