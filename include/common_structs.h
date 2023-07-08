#pragma once
#include <utility>
/*
* Some of these are likely going to be made classes soon.
* std::pair point (x,y) to serve as the key for the map.
*
* Death zone that is placed on the map is also defined in this header
*
*  ______________
* |				| ^height
* |		*		| <width>
* |				| * -> origin
* _______________
* 
* Color: RGB value (will come in handy later)
*
*/
typedef std::pair<unsigned short, unsigned short> Point;

struct Color
{
	unsigned char r;
	unsigned char b;
	unsigned char g;
};

struct Death_Zone {
	Point origin;
	unsigned short height;
	unsigned short width;
};
