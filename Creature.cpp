#include "Creature.h"
#include "Bmap.h"
#include <iostream>

void Creature::set_point(unsigned short x, unsigned short y)
{
	this->point.first = x;
	this->point.second = y;
}

Point Creature::get_point()
{
	return this->point;
}

Color Creature::get_rand_color() 
{
	Color color{};
	color.r = (rand() % 255);
	color.g = (rand() % 255);
	color.b = (rand() % 255);

	return color;
}

void Creature::move_creature(std::shared_ptr<Neuron> mn)
{
	switch(mn->type) 
	{
		case NU_UP:
			move_up();
			break;
		case NU_RIGHT:
			move_right();
			break;
		case NU_LEFT:
			move_left();
			break;
		case NU_DOWN:
			move_down();
			break;
		default:
			break;
	}
}

void Creature::move_up()
{
	Point pos = this->get_point();
	pos.second = pos.second + 1;

	if (Map::get_map().is_pos_open(pos))
	{
		Map::get_map().update_map_key(get_point(), pos);
		this->set_point(pos.second, pos.first);
	}
}

void Creature::move_right()
{
	Point pos = this->get_point();
	pos.first++;
	if (Map::get_map().is_pos_open(pos))
	{
		Map::get_map().update_map_key(get_point(), pos);
		this->set_point(pos.second, pos.first);
	}
}

void Creature::move_left()
{
	Point pos = this->get_point();
	pos.first--;
	if (Map::get_map().is_pos_open(pos))
	{
		Map::get_map().update_map_key(get_point(), pos);
		this->set_point(pos.second, pos.first);
	}
}

void Creature::move_down()
{
	Point pos = this->get_point();
	pos.second--;
	if (Map::get_map().is_pos_open(pos))
	{
		Map::get_map().update_map_key(get_point(), pos);
		this->set_point(pos.second, pos.first);
	}
}

//on the docket for re-factor
void Creature::fire_n()
{
	unsigned short rnd = rand() % neurons.size();
	move_creature(neurons.at(rnd));
}