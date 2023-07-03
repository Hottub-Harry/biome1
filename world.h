#pragma once
#define WORLD_SIZE_Y 500
#define WORLD_SIZE_X 500
#include <unordered_map>
#include <iostream>
#include "Creature.h"

class World
{
	public:

		static World& get_world()
		{
			static World instance;
			return instance;
		}

		struct Death_Zone
		{
			Pos origin;
			unsigned short width;
			unsigned short height;
		};

		/*
		* World spoecific definitions:
		* population_s: size of population
		* cycles: amount of nueral fires a generation
		* fallout: odds creature is removed anyways
		* mutation_rate: odds a random nueron is inserted during the reproductive process
		* seed: seed for random number generator
		* death_zone: rectangle defined by origin height and width
		*/
		unsigned short population_s;
		unsigned short cycles;
		float fallout;
		float mutation_rate;
		int seed;
		Death_Zone death_zone;
		
		/*
		* Fuctions:
		*  Mostly sef-explaitory
		*/

		bool is_in_death_zone(Pos pos);
		std::vector<Creature*> world_space;
		bool is_pos_open(Pos pos);
		Pos get_rand_pos(int seed);
		void cull();
		void run_cycle();
		void reproduce(Creature* c1, Creature* c2);

	private:
		 World(){
			std::cout << "Making worldspace..." << std::endl;


			population_s = 10;
			fallout = 0.0f;
			mutation_rate = 0.001f;
			seed = 293840;
			cycles = 50;
			
			death_zone.origin = Pos{ 250, 125 };
			death_zone.height = 125;
			death_zone.width = 250;


			for (int i = 0; i < population_s; i++)
			{
				Creature* tmp = new Creature();
				tmp->set_pos(get_rand_pos(seed));
				world_space.push_back(tmp);
			}
		};
};