#include "God.h"
#include <iostream>

#define x_world_size 1920
#define y_world_size 1080

//#define need_to_pause false
//#define need_to_draw  true 

God::God(WorldSize* w) :
	mWorld (w),//map
	mWindow (x_world_size, y_world_size)//gui
{
	fout.open("out.out");
}
 
God::~God() 
{
	fout.close();
};

void God::run(WorldSize* w)
{
	for (long long n = 0;;)        // Namber // progress //
	{

		for (long long pr = 0; ; ++pr)
		{
			if (w->need_to_draw) mWindow.draw(mWorld.getPresentation(),w);
			
			if (w->need_to_pause) for (int i = 0; i < 7e5; i++) {}

			//Pair<int> a;//= Event::mouse();
			//std::cout << a.x << " " << a.y << '\n';

			Event C;
			C.mouse();

			mWorld.makeTurn(w);
			if (mWorld.need_to_evolve(w))
			{
				mWorld.evolve(w);
				std::cout  << pr << '\n';    ///       << n   << ": " 
				pr = 0;
				n++;
			}
		}
	}
}

void God::run_2(WorldSize* w)
{
	for (int cnt = 1, era = 0; ; ++cnt)
	{
		if (w->need_to_draw) mWindow.draw(mWorld.getPresentation(), w);
		else if (w->need_to_draw_graph) mWindow.draw_graph();

		for (int i = 0; i < w->pause_time; i++)
		{
			std::vector<Gui::EventType> events = mWindow.get_events();
			for (int i = 0; i < events.size(); i++)
			{
				if (w->need_to_pause) for (int i = 0; i < 10e7; i++) {}
				switch (events[i])
				{
					case Gui::EventType::SWITCH_DRAW_MODE:
					{
						w->need_to_draw = !(w->need_to_draw);
						break;
					}
					case Gui::EventType::SWITCH_PAUSE:
					{
						w->mIsTurnedOff = !(w->mIsTurnedOff);
						if(w->mIsTurnedOff) std::cout << "Evolution is pause"<<std::endl;
						if (!(w->mIsTurnedOff)) std::cout << "Evolution is play" << std::endl;
						break;
					}
					case Gui::EventType::INCREASE_SPEED:
					{
						w->pause_time = (w->pause_time) + (w->pause_delta);
						break;
					}
					case Gui::EventType::DECREASE_SPEED:
					{
						w->pause_time = (w->pause_time) - (w->pause_delta);
						break;
					}
					case Gui::EventType::DRAW_GRAPH:
					{
						w->need_to_draw_graph = !(w->need_to_draw_graph);
						break;
					}
				}
			}
			
			if (!(w->need_to_draw)) break;
			
		}
		if (w->mIsTurnedOff) continue;
		
		mWorld.makeTurn(w);
		
		if (mWorld.need_to_evolve(w))
		{
			mWorld.evolve(w);
			std::cout << era << ": " << cnt << std::endl;

			fout << era << " " << cnt << std::endl;

			cnt = 0;
			++era;
						
		}
	}
}

