#ifndef SAS_HPP
#define SAS_HPP


struct WorldSize
{
	int x, y;
	int amount_bot, amount_food, amount_poison, amount_wall, amount_boot_evolue;
	bool show_cordinates = false, make_a_pause = true, need_to_draw = true, need_to_pause = false;
	bool q, mIsTurnedOff=false;
	int pause_delta =100;
	int pause_time = 10e3;
};


#endif // !SAS_HPP      