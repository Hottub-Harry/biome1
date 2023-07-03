#include "Creature.h"
#include "world.h"

void Creature::set_pos(Pos pos)
{
	this->pos.x = pos.x;
	this->pos.y = pos.y;
}

Pos Creature::get_pos()
{
	return this->pos;
}

Color Creature::get_rand_color() 
{
	Color color{};
	color.r = (rand() % 255);
	color.g = (rand() % 255);
	color.b = (rand() % 255);

	return color;
}

void Creature::move_creature(Neuron * mn)
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
	Pos pos = this->get_pos();
	pos.y++;
	if (World::get_world().is_pos_open(pos))
	{
		this->set_pos(pos);
	}
}

void Creature::move_right()
{
	Pos pos = this->get_pos();
	pos.x++;
	if (World::get_world().is_pos_open(pos))
	{
		this->set_pos(pos);
	}
}

void Creature::move_left()
{
	Pos pos = this->get_pos();
	pos.x--;
	if (World::get_world().is_pos_open(pos))
	{
		this->set_pos(pos);
	}
}

void Creature::move_down()
{
	Pos pos = this->get_pos();
	pos.y--;
	if (World::get_world().is_pos_open(pos))
	{
		this->set_pos(pos);
	}
}

void Creature::fire_n()
{
	unsigned short rnd = rand() % neurons.size();
	move_creature(neurons.at(rnd));
}