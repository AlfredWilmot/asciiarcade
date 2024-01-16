#include <gtest/gtest.h>
#include "GameEntityStack.h"

TEST(GameEntityStack, throws_exception_when_trying_to_get_from_empty_stack)
{
    int number_of_entities=0;
    GameEntityStack game_stack(number_of_entities);
    for (int idx=-1; idx<100; idx++) {
        EXPECT_THROW(
            {game_stack.get(idx);},
            std::invalid_argument
        );
    }
}

//TEST(GameEntityStack, todo)
//{
//    FAIL();
//}
