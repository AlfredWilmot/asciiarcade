#include <gtest/gtest.h>
#include "GameEntityStack.h"

TEST(GameEntityStack, cannot_create_an_empty_stack)
{
    for (int stack_size=-1; stack_size<100; stack_size++) {
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
TEST(GameEntityStack, number_of_entities_on_stack_equals_number_added_to_stack)
{
    for (int stack_size=1; stack_size<100; stack_size++) {
        GameEntityStack game_stack(stack_size);
        int expected = stack_size;
        int actual = game_stack.max_count();
        ASSERT_EQ(expected, actual);
    }

}

TEST(GameEntityStack, total_entities_added_cannot_exceed_the_stack_size)
{
    for (int stack_size=1; stack_size<100; stack_size++) {
        GameEntityStack game_stack(stack_size);
        for (int entity_count{}; entity_count<100; entity_count++) {
            if (game_stack.count() >= game_stack.max_count()) {
                EXPECT_THROW(
                    {game_stack.add(GameEntity());},
                    std::invalid_argument
                );
            }
            else
            {
                EXPECT_NO_THROW({game_stack.add(GameEntity());});
            }
            
        }
    };
}

//TEST(GameEntityStack, todo)
//{
//    FAIL();
//}
