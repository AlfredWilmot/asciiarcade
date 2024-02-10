#include <cstddef>
#include <gtest/gtest.h>
#include <stdexcept>
#include "GameEntityStack.h"

size_t STACK_SIZE = 5;
Particle TEST_PARTICLE({
    .mass=1.0,
    .position{.x=0.0, .y=0.0},
    .velocity{.x=0.0, .y=0.0},
    .acceleration{.x=0.0, .y=0.0},
});
Particle ANOTHER_TEST_PARTICLE({
    .mass=1.0,
    .position{.x=1.0, .y=1.0},
    .velocity{.x=0.0, .y=0.0},
    .acceleration{.x=0.0, .y=0.0},
});

GameEntityStack create_entity_stack(size_t stack_length){
    /* Returns a fixed-length stack for testing purposes */

    GameEntityStack game_stack(stack_length);

    for (int i{}; i <stack_length; i++) {
     
        Particle particle(
            {
                .mass = 1.0,
                .position = {.x=float(i), .y=0},
                .velocity = {.x=0, .y=0},
                .acceleration= {.x=0, .y=0},
            }
        );

        game_stack.add(particle);
    };

    return game_stack;

};

TEST(GameEntityStack, create_a_list_of_entities)
{
    GameEntityStack game_stack = create_entity_stack(STACK_SIZE);
}

TEST(GameEntityStack, cannot_create_an_empty_stack)
{
    for (int stack_size=-1; stack_size<STACK_SIZE; stack_size++) {
        if (stack_size<1) {
            EXPECT_THROW(
                {GameEntityStack game_stack(stack_size);},
                std::invalid_argument
            );
        }
        else {
            EXPECT_NO_THROW({GameEntityStack game_stack(stack_size);});
        }
    }
}

TEST(GameEntityStack, total_entities_added_cannot_exceed_the_stack_size)
{
    for (int stack_size=1; stack_size<STACK_SIZE; stack_size++) {
        GameEntityStack game_stack(stack_size);
        for (int entity_count=1; entity_count<STACK_SIZE; entity_count++) {
            Particle some_particle({
                .position={
                    .x=float(entity_count),
                    .y=0
                },
            });
            if (entity_count > stack_size) {
                EXPECT_THROW(
                    game_stack.add(some_particle),
                    std::overflow_error
                );
            }
            else {
                game_stack.add(some_particle);
            }
        }
    };
}

TEST(GameEntityStack, can_add_entity_when_not_exceeding_stack_size)
{
    for (int stack_size=1; stack_size<STACK_SIZE; stack_size++) {
        GameEntityStack game_stack(stack_size);
        for (int entity_count=1; entity_count<STACK_SIZE; entity_count++) {
            Particle some_particle({
                .position={
                    .x=float(entity_count),
                    .y=0
                },
            });
            if (entity_count <= stack_size) {
                EXPECT_NO_THROW(game_stack.add(some_particle));
            }
        }
    };
}

TEST(GameEntityStack, no_two_particles_can_share_the_same_coordinates)
{
    GameEntityStack game_stack(STACK_SIZE);
    Particle mars=TEST_PARTICLE;
    Particle venus{};
    Particle earth({
        .position={.x=0,.y=0},
        .velocity=Cartesian({})
    });

    game_stack.add(mars);
    EXPECT_THROW(game_stack.add(venus), std::invalid_argument);
}

//TEST(GameEntityStack, todo)
//{
//    FAIL();
//}
