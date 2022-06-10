#include "Gui.h";
#include "Map.h";
#include "God.h";
#include "sas.hpp";

#include <filesystem>
#include <iostream>

#include <thread>

void first_message(WorldSize* w)
{
	std::cout << "How much world?" << std::endl;
	std::cin >> w->x >> w->y;
	std::cout << "How much bot?" << std::endl;
	std::cin >> w->amount_bot;
	std::cout << "How much poison?" << std::endl;
	std::cin >> w->amount_poison;
	std::cout << "How much food?" << std::endl;
	std::cin >> w->amount_food;
	std::cout << "How much wall?" << std::endl;
	std::cin >> w->amount_wall;
	std::cout << "How mauch bot to evolue?" << std::endl;
	std::cin >> w->amount_boot_evolue;
	std::cout << std::endl;
}

int main()
{
	WorldSize w;
	first_message(&w);

	God g(&w);
	g.run(&w);
}