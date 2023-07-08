#pragma once
#include <iostream>
#include <cstdlib>
#include "Bmap.h"
#include "creature.h"

class World
{
	public:

		static World& get_world()
		{
			static World instance;
			return instance;
		}
		/*
		* World Variables
		*/
		//See Map.h
		Map world_space;

		//creatures alive currently in world
		std::vector<std::shared_ptr<Creature>> creatures;

		//inital population size
		unsigned short population_s;

		//number of neuron fires per generation
		unsigned short cycles;

		//Chance creatures die anyways
		float fallout;

		//odds a random neuron is factored into the reproduction process
		float mutation_rate;

		//rng seed for rng things
		int seed;

		/*
		* 
		* Member functions of world
		* 
		* World refactored to only control lifecycle, removed map operations
		*/

		/*
		* Cull kills creatures in the "kill zone"
		*/
		int cull();

		/*
		* Fires 1 creature neurons 1 time
		*/
		void run_cycle();

		/*
		* Mixes genes of 2 parents, adds offspring to the map
		*/
		//void reproduce(Creature* c1, Creature* c2);

	private:
		 World(){
			std::cout << "Making worldspace..." << std::endl;
			std::srand(seed);


			population_s = 10;
			fallout = 0.0f;
			mutation_rate = 0.001f;
			seed = 293840;
			cycles = 50;


			for (int i = 0; i < population_s; i++)
			{
				std::shared_ptr<Creature> tmp(new Creature);
				Point pt = world_space.get_rand_point();
				tmp->set_point(pt.first,pt.second);
				Map::get_map().map.emplace(pt, tmp);
				creatures.push_back(tmp);
			}
		};
};
