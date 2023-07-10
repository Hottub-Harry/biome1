#include "world.h"

/*
* Cull kills creatures in the "kill zone"
*/
int World::cull()
{
	int death_count = 0;
	for (int i = 0; i < (int)creatures.size(); i++)
	{
		if (Map::get_map().is_in_death_zone(creatures.at(i)->point))
		{
			Map::get_map().map.erase(creatures.at(i)->point);
			creatures.erase(std::remove(creatures.begin(), creatures.end(), creatures.at(i)));
			i--;
			death_count++;
		}
	}
	return death_count;
}

/*
* Fires each creature's neuron 1 time.
*/
void World::run_cycle()
{
	for (auto& creature : creatures)
	{
		creature->fire_n();
	}
}

/*
* Method for adding a creature
* ONLY USE THIS TO ADD CREATURES
*/
void World::add_creature( Point point, std::shared_ptr<Creature> creature)
{
	//add it to the vector of creatures that are alive
	creatures.push_back(creature);
	Map::get_map().map.emplace( point, creature);
}

/*
* Call to initialize world, only call once
* cannot manipulate other methods after initialization
*/
void World::init()
{
	std::srand(this->seed);
	for(int i = 0; i < population_s; i++)
	{
		std::shared_ptr<Creature> tmp(new Creature);
		Point pt = world_space.get_rand_point();
		tmp->set_point(pt.first,pt.second);
		add_creature(pt,tmp);
	}	
}

/*
* Starting population for the world
*/
void World::set_starting_population(unsigned short pop)
{
	this->population_s = pop; 
}

/*
* Chance a creature will die reguardless of cull condition
*/
void World::set_fallout(float f)
{
	this->fallout = f;
}

/*
* Chance a random neuron is inserted into the genepool
*/
void World::set_mutation_rate(float mut)
{
	this->mutation_rate = mut;
}

/*
* RNG seed
*/
void World::set_seed(int s)
{
	this->seed = s;
}

/*
* amount of neural fires between prunings
*/
void World::set_cycles(int c)
{
	this->cycles = c;
}

/*
* amount of total mating cycles
*/
void World::set_generations(int g)
{
	this->generations = g;
}
