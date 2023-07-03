#pragma once
#include <vector>
#include "Neuron.h"

struct Color
{
	unsigned char r;
	unsigned char b;
	unsigned char g;
};

struct Pos
{
	unsigned short x;
	unsigned short y;
};


class Creature
{
	private:
		void move_up();
		void move_left();
		void move_right();
		void move_down();

	public: 
		std::vector<Neuron*> neurons;
		Color color{};
		Color get_rand_color();
		Pos pos{};
		void set_pos(Pos pos);
		Pos get_pos();
		void move_creature(Neuron * mn);
		void fire_n();
		unsigned char n_num = 8;

		Creature()
		{
			color = get_rand_color();

			for (int i = 0; i < n_num; i++)
			{
				neurons.push_back(new Neuron());
			}
		}
		~Creature() 
		{}
};