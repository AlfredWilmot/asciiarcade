#include <gtest/gtest.h>
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

TEST(SceneTest, cannot_initialize_scene_with_invalid_background)
{
    EXPECT_ANY_THROW({
        Scene scene(invalid_background_scene);
    });
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

TEST(SceneTest, todo)
{
    FAIL();
}
