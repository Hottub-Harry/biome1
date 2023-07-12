#pragma once
#include <vector>
#include <utility>
#include <memory>
#include "neuron.h"
#include "common_structs.h"


class Creature
{
	private:
		void move_up();
		void move_left();
		void move_right();
		void move_down();

	public: 
		std::vector<std::shared_ptr<Neuron>> neurons;
		Color color{};
		Point point{};
		unsigned char n_num = 8;

		Color get_rand_color();
		void set_point(unsigned short x, unsigned short y);
		Point get_point();
		void move_creature(std::shared_ptr<Neuron> mn);
		void fire_n();
		void mate(std::shared_ptr<Creature> other_parent);
		

		Creature()
		{
			color = get_rand_color();
			for (int i = 0; i < n_num; i++)
			{
				neurons.push_back(std::shared_ptr<Neuron>(new Neuron()));
			}
		};
};