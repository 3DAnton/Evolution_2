#ifndef Event_H
#define Event_H

#include "Domain.h"


class Event
{
public:
	Event();
	Pair<int> mouse();

	~Event();
};

#endif // !Event_H