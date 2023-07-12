#include "world.h"
#include <iostream>

int main()
{
	World * world = World::get_world();
	world->set_seed(15);
	world->set_cycles(250);
	world->set_generations(10);
	world->set_starting_population(50);
	world->init();

	world->run_generation();
}
