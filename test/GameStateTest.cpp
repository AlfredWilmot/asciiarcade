#include <gtest/gtest.h>
#include "GameEntityStack.h"

TEST(GameEntityStack, throws_exception_when_accessing_out_of_bounds)
{
    int number_of_entities=0;
    GameEntityStack game_stack(number_of_entities);
    EXPECT_THROW(
        {game_stack.get(0);},
        std::invalid_argument
    );
}

//TEST(GameEntityStack, todo)
//{
//    FAIL();
//}
