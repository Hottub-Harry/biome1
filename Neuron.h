#pragma once
#include <vector>

enum mn_type
{
	NU_UP,
	NU_DOWN,
	NU_LEFT,
	NU_RIGHT,
};
class Neuron
{ 
	public:
		mn_type type{};
	Neuron()
	{
		type = mn_type(rand() % 4);
	}
};

