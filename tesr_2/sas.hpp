#ifndef SAS_HPP
#define SAS_HPP


struct WorldSize
{
	int x, y;
	int amount_bot, amount_food, amount_poison, amount_wall, amount_boot_evolue;
	bool show_cordinates = false, make_a_pause = true, need_to_draw = true, need_to_pause = false;
	bool q, mIsTurnedOff=false, need_to_draw_graph= false;
	int pause_delta =100;
	int pause_time = 10e3;
	int x_draw = 10, y_draw = 10;
	bool need_to_zad = false,need_to_move=true;
};


#endif // !SAS_HPP      