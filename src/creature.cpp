#include "creature.h"
#include "Bmap.h"
#include "world.h"
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

	if (Map::get_map()->is_pos_open(pos))
	{
		Map::get_map()->update_map_key(this->point, pos);
		this->set_point(pos.first, pos.second);
	}
}

void Creature::move_right()
{
	Point pos = this->get_point();
	pos.first++;
	if (Map::get_map()->is_pos_open(pos))
	{
		Map::get_map()->update_map_key(this->point, pos);
		this->set_point(pos.first, pos.second);
	}
}

void Creature::move_left()
{
	Point pos = this->get_point();
	pos.first--;
	if (Map::get_map()->is_pos_open(pos))
	{
		Map::get_map()->update_map_key(this->point, pos);
		this->set_point(pos.first, pos.second);
	}
}

void Creature::move_down()
{
	Point pos = this->get_point();
	pos.second--;
	if (Map::get_map()->is_pos_open(pos))
	{
		Map::get_map()->update_map_key(this->point, pos);
		this->set_point(pos.first, pos.second);
	}
}

//on the docket for re-factor
void Creature::fire_n()
{
	//track the number of moves
	static unsigned char n_moves = 0;

	move_creature(neurons.at(n_moves));

	//prevent running off the end of the vector
	if(n_moves == neurons.size() - 1)
	{
		n_moves = 0;
	}
}

/*
* use .mate on one parent to return a random mix between two parents
*/
void Creature::mate(std::shared_ptr<Creature> other_parent)
{
	//make child and dump out the random nuerons thrown in there
	std::shared_ptr<Creature> child(new Creature);
	child->neurons.empty();

	//mix neurons
	for(int i = 0; i < other_parent->neurons.size(); i++)
	{
		// float mut_roll = (rand() % 1000) / 1000;
		// //within 1/1000
		// //Considered the "exploration" part of machine learning
		// if( ( mut_roll > World::get_world().mutation_rate - 0.0005 ) && ( mut_roll < World::get_world().mutation_rate + 0.0005 ))
		// {
		// 	std::shared_ptr<Neuron> nn (new Neuron);
		// 	nn->type = mn_type(rand() % 4);
		// 	continue;
		// }

		if(rand() % 1)
		{
			child->neurons.push_back(this->neurons.at(i));
		}
		else
		{
			child->neurons.push_back(other_parent->neurons.at(i));
		}
		
	}

	//mix colors
	child->color.r = (this->color.r + other_parent->color.r) / 2;
	child->color.b = (this->color.b + other_parent->color.b) / 2;
	child->color.g = (this->color.g + other_parent->color.g) / 2;

	Point rpoint = Map::get_map()->get_rand_point();

	child->point = rpoint;

	World::get_world()->add_creature(rpoint, std::move(child));

}