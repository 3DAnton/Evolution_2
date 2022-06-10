#include "God.h"
#include <iostream>

#define x_world_size 1920
#define y_world_size 1080

//#define need_to_pause false
//#define need_to_draw  true 

God::God(WorldSize* w) :
	q (w),//map
	y (x_world_size, y_world_size)//gui
{

}
 
God::~God() {};

void God::run(WorldSize* w)
{
	for (long long n = 0;;)        // Namber // progress //
	{

		for (long long pr = 0; ; ++pr)
		{
			if (w->need_to_draw) y.draw(q.getPresentation(),w);

			if (w->need_to_pause) for (int i = 0; i < 7e5; i++) {}

			//Pair<int> a;//= Event::mouse();
			//std::cout << a.x << " " << a.y << '\n';

			Event C;
			C.mouse();

			q.makeTurn(w);
			if (q.need_to_evolve(w))
			{
				q.evolve(w);
				std::cout  << pr << '\n';    ///       << n   << ": " 
				pr = 0;
				n++;
			}
		}
	}
}
