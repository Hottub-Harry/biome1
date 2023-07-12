#include "world.h"


World * World::instance = nullptr;
/*
* Cull kills creatures in the "kill zone"
*/
int World::cull()
{
	int death_count = 0;
	for (int i = 0; i < (int)creatures.size(); i++)
	{
		if (Map::get_map()->is_in_death_zone(creatures.at(i)->point))
		{
			Map::get_map()->map.erase(creatures.at(i)->point);
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
* Runs X cycles, ends with a cull() and mating cycle.
*/
void World::run_generation()
{
	int population;

	for(int i = 0; i < this->generations; i++)
	{
		//this is for debugging
		population = creatures.size();

		if(!population)
		{
			std::cout << "All creatures have died." << std::endl;
			return;
		}

		std::cout << "GENERATION: " << i << std::endl << "STARTING POPULATION: " << population << std::endl;
		run_cycle();
		//debugging
		for(auto & creature : creatures)
		{
			std::cout << "X: " << creature->get_point().first << " Y: " << creature->get_point().second << std::endl;
		}
		std::cout << "CULL COMMENCING" << std::endl;

		cull();

		//debugging
		std::cout << population - creatures.size() << " CREATURES KILLED." << std::endl
		<< "STARTING MATING CYCLE:" << std::endl;
		population = creatures.size();
		mating_cycle();
		std::cout << "CHILDREN ADDED: " << creatures.size() - population << std::endl;

		std::cout << "RANDOMIZING POSITIONS..." << std::endl;
		randomize_positions();

	}
}

/*
* Method for adding a creature
* ONLY USE THIS TO ADD CREATURES
*/
void World::add_creature( Point point, std::shared_ptr<Creature> creature)
{
	//add it to the vector of creatures that are alive
	this->creatures.push_back(creature);
	Map::get_map()->map.emplace( point, creature);
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

/*
* Mating cycle -- creatures mate with the nearest creature
*/

void World::mating_cycle()
{
	//map of flags to reference to check who has mated
	std::map<int, bool> has_mated;

	//track the shortest dist
	float shortest_dist = MAXFLOAT;
	int shorest_index =  0;

	int inital_size = creatures.size();

	if(inital_size == 1)
	{
		return;
	}

	//find nearest and mate
	for(int i = 0; i < inital_size; i++)
	{
		if(has_mated.find(i)->second)
		{
			continue;
		}
		//grab point of first creature
		Point pt1 = creatures.at(i)->get_point();

		//compare to the others
		for(int j = i + 1; j < creatures.size(); j++)
		{
			Point pt2 = creatures.at(j)->get_point();
			float distance = sqrt( pow(( pt2.second - pt1.second), 2) + pow((pt2.first - pt1.first), 2));

			if(distance < shortest_dist)
			{
				shortest_dist = distance;
				shorest_index = j;
			}
		}

		//mate creature i with nearest distance and mark both as mated
		creatures.at(i)->mate(creatures.at(shorest_index));
		//mark both as mated
		has_mated.emplace(i, true);
		has_mated.emplace(shorest_index, true);

		if((inital_size - has_mated.size()) == 1)
		{
			break;
		}
	}
}

void World::randomize_positions()
{

	for(auto creature : creatures)
	{
		Point rand_pt = world_space.get_rand_point();

		Map::get_map()->update_map_key(creature->get_point(), rand_pt);

		creature->set_point(rand_pt.first, rand_pt.second);
	}
}
