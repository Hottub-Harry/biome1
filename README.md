# biome1


# Getting started

Clone this repository, and include the files in your project.

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

TODO

# Contribute

Code reviews are welcome, forks are encouraged, ideas are celebrated. This is mainly a personal project of mine, but if someone comes along more senior that has experience reviewing code, by all means say something. 

# Roadmap

There is still a lot to be done. Tests, and a GUI is in the works. Adding interesting new neuron types as well as other methods to control populations.
