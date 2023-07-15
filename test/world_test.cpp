#include "world.h"
#include "gtest/gtest.h"

TEST(WorldTest, handles_init)
{
    int creaures_to_add = 5;
    int seed = 123;


    World * world = World::get_world();
    world->set_starting_population(creaures_to_add);
    world->set_seed(seed);
    world->init();

    ASSERT_EQ(seed, world->seed);
    ASSERT_EQ(creaures_to_add, world->creatures.size());
}