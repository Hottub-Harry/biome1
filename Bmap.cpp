#include "Bmap.h"
#include <iostream>

bool Map::is_pos_open(Point point)
{
	if (point.first > width || point.second > height || point.first < 0 || point.second < 0)
	{
		return false;
	}
	if (!map.contains(point))
	{
		return true;
	}
	return false;
}

Point Map::get_rand_point()
{
	Point point{};

	do {
		point.first = rand() % width;
		point.second = rand() % height;

	} while (!is_pos_open(point));

	return point;
}

bool Map::is_in_death_zone(Point point)
{
	auto top = death_zone.origin.second + death_zone.height;
	auto bot = death_zone.origin.second - death_zone.height;
	auto left = death_zone.origin.first - death_zone.width;
	auto right = death_zone.origin.first + death_zone.width;

	/*
	* less than top
	*/
	if (((point.second < top) && (point.second > bot)) && ((point.first < right) && (point.first > left)))
	{
		return true;
	}
	return false;
}

void Map::update_map_key(Point old_point, Point new_point)
{
	auto nh = map.extract(old_point);
	nh.key() = new_point;
	map.insert(std::move(nh));
}

