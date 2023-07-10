#include "world.h"
#include <iostream>

int main()
{
	std::srand(145);
	World world = World::get_world();
	world.set_seed(15);
	world.init();

	for (auto& creature : world.creatures)
	{
		std::cout << "X: " << creature->point.first << " Y: " << creature->point.second << std::endl;
	}

	for (int i = 0; i < 50; i++)
	{
		world.run_cycle();
	}
	int killed = world.cull();
	std::cout << "Creatures Killed: " << killed << std::endl;
	std::cout << "After CULL: " << std::endl;
	for (auto& creature : world.creatures)
	{
		std::cout << "X: " << creature->point.first << " Y: " << creature->point.second << std::endl;
	}
}
