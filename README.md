# biome1


# Getting started

Clone this repository, and include the files in your project, or fork this repository and experiment with it yourself.

You should download the Meson build system in order to build the project and run it on your system. 


# Vision

This project describes a tiny world in which creatures can fire motor neurons to move around. The project consists of a "death zone" that kills any creature inside of it. Creatures are rewarded with
a mating cycle after successful evasion if the death zone. During the mating cycle, the creatures mix neurons and colors to produce offspring. Although my code contains a "main" method, you can certainly 
delete it and use the methods and classes on your own to see what you discover.

# World Overview

Each world defaults to a 500 by 500 grid, with the origin being in the bottom-left corner. The world has a Map class (stored in Bmap for biome-map) which contains an ordered hashtable of (x,y) keys and shared pointer
values (pointing to a creature). This was done so that checking a position in the world is lightning quick. Furthermore, a vector of shared pointers in the world class tracks all of the creatures currently alive in the world.
This is done so we have faster lookup speeds when getting the creatures and their position. So, instead of checking the position of every creature for N creatures before a movement is made from one grid space to another (O(N^2)), 
it is O(logn) the time complexity of std::map. When a creature needs inserted or deleted from the world, instead of iterating the map, I simply grab the position from the vector (we must iterate the vector to preform creature operations anyways)
and pass it to the hash table, and vector.erase() for deletion. When the pointer is removed from both locations, it automatically deallocates the creature from memory via smart pointer.

# Neural Networks

I hate to burst your bubble, but these barely meet the definition of neural networks, I just call them that. Currently, there are 4 motor neuron types that control the movement of the creature. The only connection
they have with each other is firing order. The order of firing and the nueron types themselves are inheirited from parents, save for the original generation which is the equivalent of lab-grown creatures. The neurons
each creature has are included in a vector within the Creature class. They will fire sequentially, from start to finish, untill I can come up with a better representation of a neural network. 


# Methods

I will not go over the entirety of the methods here, but I will give a general overview of how to use this project.

To start `#include "world.h"`. The naming of this file is sure to change to `biome1.h`, because world is ambiguous. `world.h` includes almost every other file in the project, and it manages the lifecycle of everything.

For example:
```
#include "world.h"

int main()
{
  //returns your instance of world -- is a singleton
  World world = world.get_world();
  world.set_seed(1337) //set the seed for the random number generator
  world.set_starting_population(50); //starting population of creatures in the world
  world.set_cycles(100); //should be suffcient for the space provided -- # of nueron fires b4 cull/mating
  world.set_generations(50); //however many generations you wish to run
  world.init(); //runs setup tasks for the world. Randomizes locations and neurons of creatures.

  world.run_generation(); //runs the amount of generations specified   

}
```

So, in a few simple lines of code, you can begin training the creatures (via natural selection) to avoid the "death zone". 

While the `world.run_generation()` command is handy, it is opinionated. If you want to run your own generations, with custom settings, you certainly can.

The "death_zone" needs some small tweaks yet, but it is defaulted to the bottom half of the world space.

# Lifecycle methods

There are a few things that happen during the life of the creature. The first of which is being born. The generation 0 is crafted by god (you), and has all of their colors and brain parts randomly placed. Every subsequent generation is determined by the parents. The children of a parent will randomly have neurons assigned from each parent, and the color is mixed. 

After being born, the creatures will worm their way around, likely moving randomly at first. This phase is described in `run_cycle()`. Each creature fires its neurons and moves around. Perhaps I can add food or predation mechanics here later.

After the roaming period, the `cull()` is preformed.

I will just leave this here:
*cull : noun  a selective slaughter of wild animals.*

After the cull a mating cycle is initiated. The creatures mate with those that are closest to them. If one is left without a mate, tough luck. The children are then born into a world of peril.

# Contribute

Code reviews are welcome, forks are encouraged, ideas are celebrated. Could use a poor soul to write some unit tests in gTest. Would like to open collaboration about refactoring ideas.

# Roadmap

Hello everyone, I am reviving this project. I was caught up in a lot of work and grad school things, and now with the semester over, I will have 8-10 hours a week to throw at the project. With that out of the way, we can begin talking about exciting refactors in the works. 

## Upcoming refactors

Firstly, I would like to change how neurons work. Rather than a sequential firing, I want to move more towards a conventional neural network for each creature. The children will inheirit weight values rather than a mix of neuron types from parents. 

Secondly, I would like to move the project into the rust programming language. This way, the project can have modularity and better natural growth, and peices can offer better reuse to others via the rust crates ecosystem. This starts with certain "footings" being put in place. Firstly, making a neuron crate from nothing but the standard library. The name has not been decided, but I am leaning towards the name tinyNeurons. It will be lightweight and have no dependancies. 

With this being said, these large refactors means that this repository will no longer be supported by myself. Instead I will set up a few new repositories, and dedicate my time there. This repository will remain, and will still accept pull requests from people who wish to maintain it, as well as host some general project discussion. 
