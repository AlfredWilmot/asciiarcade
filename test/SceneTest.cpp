#include <gtest/gtest.h>
#include <stdexcept>
#include "data/scene_test_data.h"
#include "Scene.h"

/*
- initialize scene with a background
- add ascii to scene
- list objects in scene
- if I add n objects to the scene, the list returns n objects
*/

TEST(SceneTest, newly_initialized_scene_only_prints_background)
{
    Scene scene(valid_background_scene);
    const char * expected = valid_background_scene;
    const char * actual = scene.print();
    EXPECT_STREQ(expected, actual);
}

TEST(SceneTest, throws_no_exception_initializing_scene_with_valid_background)
{
    EXPECT_NO_THROW(Scene scene(valid_background_scene););
}

TEST(SceneTest, throws_exception_initializing_scene_using_background_with_misaligned_newlines)
{
    std::cout << invalid_background_with_newlines_on_different_columns << std::endl;
    EXPECT_THROW(
        {Scene scene(invalid_background_with_newlines_on_different_columns);},
        std::invalid_argument
    );
}

TEST(SceneTest, throws_exception_initializing_scene_using_background_with_no_newlines)
{
    std::cout << invalid_background_with_no_newlines << std::endl;
    EXPECT_THROW(
        {Scene scene(invalid_background_with_no_newlines);},
        std::invalid_argument
    );
}

TEST(SceneTest, scene_height_matches_row_count_of_background_when_printed)
{
    Scene scene(valid_background_scene);
    int expected = expected_scene_height;
    int actual = scene.height();
    EXPECT_EQ(expected, actual);

}

TEST(SceneTest, scene_width_matches_column_count_of_background_when_printed)
{
    Scene scene(valid_background_scene);
    int expected = expected_scene_width;
    int actual = scene.width();
    EXPECT_EQ(expected, actual);
}

//TEST(SceneTest, todo)
//{
//    FAIL();
//}
