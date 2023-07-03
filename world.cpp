#include "world.h"

int World::cull()
{
	int death_count = 0;
	for (int i = 0; i < creatures.size(); i++)
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

void World::run_cycle()
{
	for (auto& creature : creatures)
	{
		creature->fire_n();
	}
}

//TODO: Refactor to work with map

//void World::reproduce(Creature* c1, Creature* c2)
//{
//	int split = c1->neurons.size() / 2;
//	std::vector<Neuron*> child_n;
//	for (int i = 0; i < split; i++)
//	{
//		child_n.push_back(c1->neurons.at(i));
//	}
//
//	for (int i = 0; split + i < c1->neurons.size(); i++)
//	{
//		child_n.push_back(c2->neurons.at(i));
//	}
//
//
//	Creature* child = new Creature();
//	child->neurons = child_n;
//	child->pos = get_rand_pos(seed);
//
//	world_space.push_back(child);
//}