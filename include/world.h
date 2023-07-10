#pragma once
#include <iostream>
#include <memory>
#include "common_structs.h"
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
		std::vector<std::shared_ptr<Creature>> creatures;
		unsigned short population_s;
		unsigned short cycles;
		float fallout;
		float mutation_rate;
		int seed;
		int generations;

		/*
		* 
		* Member functions of world
		* 
		* World refactored to only control lifecycle, removed map operations
		*/

		int cull();
		void run_cycle();
		void add_creature(Point point, std::shared_ptr<Creature> creature);
		void init();
		void set_starting_population(unsigned short pop);
		void set_fallout(float f);
		void set_mutation_rate(float mut);
		void set_seed(int s);
		void set_cycles(int c);
		void set_generations(int g);


	private:
		 World(){
			std::cout << "Making worldspace... VERSION 0.1" << std::endl;
			/*
			* Defaults
			*/
			population_s = 10;
			fallout = 0.0f;
			mutation_rate = 0.001f;
			seed = 29385;
			cycles = 50;
		};
};
