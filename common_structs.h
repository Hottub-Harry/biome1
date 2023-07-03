#pragma once
#include <utility>

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
