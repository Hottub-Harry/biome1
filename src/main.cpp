#include "world.h"
#include <iostream>

int main(void)
{
	World world = World::get_world();
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
	system("pause");
}