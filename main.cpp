#include "world.h"
#include <iostream>

int main(void)
{
	World world = World::get_world();

	for (auto creature : world.world_space)
	{
		std::cout << "X: " << creature->get_pos().x << " Y: " << creature->get_pos().y << std::endl;
	}

	for (int i = 0; i < 50; i++)
	{
		world.run_cycle();

		std::cout << "CYCLE: " << i << std::endl;
		for (auto creature : world.world_space)
		{
			std::cout << "X: " << creature->get_pos().x << " Y: " << creature->get_pos().y << std::endl;
		}
	}
	world.cull();

	for (int i = 0; i < world.world_space.size() / 2; i++)
	{
		world.reproduce(world.world_space.at(i), world.world_space.at(i + 1));
	}

	std::cout << "After Cull:" << std::endl << std::endl;
	for (auto creature : world.world_space)
	{
		
		std::cout << "X: " << creature->get_pos().x << " Y: " << creature->get_pos().y << std::endl;
	}
}