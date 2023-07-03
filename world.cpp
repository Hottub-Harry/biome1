#include "world.h"
#include "creature.h"

bool World::is_pos_open(Pos pos)
{
	if (pos.x > WORLD_SIZE_X || pos.y > WORLD_SIZE_Y || pos.x < 0 || pos.y < 0)
	{
		return false;
	}

	for (auto creature : world_space)
	{
		Pos tmp_pos = creature->get_pos();
		if (pos.x == tmp_pos.x && pos.y == tmp_pos.y)
		{
			return false;
		}
	}

	return true;
}

Pos World::get_rand_pos(int seed)
{
	std::srand(seed);

	Pos pos{};

	do {
		pos.x = (rand() % WORLD_SIZE_X);
		pos.y =	(rand() % WORLD_SIZE_Y);
	} 
	while (!is_pos_open(pos));
	
	return pos;
}

bool World::is_in_death_zone(Pos pos)
{
	auto top = death_zone.origin.y + death_zone.height;
	auto bot = death_zone.origin.y - death_zone.height;
	auto left = death_zone.origin.x - death_zone.width;
	auto right = death_zone.origin.x + death_zone.width;
	/*
	* less than top
	*/
	if ( ( (pos.y < top) && (pos.y > bot) ) && ( (pos.x < right) && (pos.x > left) ) )
	{
		return true;
	}

	return false;
}

void World::cull()
{
	for (int i = 0; i < world_space.size(); i++)
	{
		if (is_in_death_zone(world_space.at(i)->get_pos()))
		{
			Creature* ptr = world_space.at(i);
			world_space.erase(std::remove(world_space.begin(), world_space.end(), world_space.at(i)));

			delete(ptr);
			i--;
		}
	}
}

void World::run_cycle()
{
	for (auto creature : world_space)
	{
		creature->fire_n();
	}
}

void World::reproduce(Creature* c1, Creature* c2)
{
	int split = c1->neurons.size() / 2;
	std::vector<Neuron*> child_n;
	for (int i = 0; i < split; i++)
	{
		child_n.push_back(c1->neurons.at(i));
	}

	for (int i = 0; split + i < c1->neurons.size(); i++)
	{
		child_n.push_back(c2->neurons.at(i));
	}


	Creature* child = new Creature();
	child->neurons = child_n;
	child->pos = get_rand_pos(seed);

	world_space.push_back(child);
}