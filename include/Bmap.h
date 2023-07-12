#pragma once
#include <utility>
#include <map>
#include <memory>
#include "creature.h"
#include "common_structs.h"

class Map
{
	private:
		static Map * instance;

	public:

		/*
		* SINGLETON FOR MAP
		*/
		static Map * get_map()
		{
			if(instance == nullptr)
			{
				instance = new Map();
			}
			return instance;
		}

		/*
		* Vars:
		*/
		std::map< Point, std::shared_ptr<Creature> > map;
		unsigned short width;
		unsigned short height;
		Death_Zone death_zone{};

		/*
		* Setters/getters for world width/height
		*/
		inline void set_height(unsigned short height) { this->height = height; }
		inline void set_width(unsigned short width) { this->width = width; }

		bool is_pos_open(Point point);
		Point get_rand_point();
		bool is_in_death_zone(Point point);
		void update_map_key(Point old_point, Point new_point);


		/*
		* width and height set to 500
		* death_zone initialized to bottom half of map
		*/
		Map()
		{
			width = 500;
			height = 500;
			death_zone.origin = Point{ 250,125 };
			death_zone.width = 250;
			death_zone.height = 125;

		};		
};