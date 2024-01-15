#include <gtest/gtest.h>
#include <stdexcept>
#include "data/scene_test_data.h"
#include "SceneView.h"
#include <tuple>

TEST(SceneViewTest, newly_initialized_scene_only_prints_background)
{
    SceneView scene(valid_background_scene);
    const char * expected = valid_background_scene;
    const char * actual = scene.print();
    EXPECT_STREQ(expected, actual);
}

TEST(SceneViewTest, throws_no_exception_initializing_scene_with_valid_background)
{
    EXPECT_NO_THROW(SceneView scene(valid_background_scene););
}

TEST(SceneViewTest, throws_exception_initializing_scene_using_background_with_misaligned_newlines)
{
    EXPECT_THROW(
        {SceneView scene(invalid_background_with_newlines_on_different_columns);},
        std::invalid_argument
    );
}

TEST(SceneViewTest, throws_exception_initializing_scene_using_background_with_no_newlines)
{
    EXPECT_THROW(
        {SceneView scene(invalid_background_with_no_newlines);},
        std::invalid_argument); }

TEST(SceneViewTest, scene_height_matches_row_count_of_background_when_printed)
{
    SceneView scene(valid_background_scene);
    int expected = expected_scene_height;
    int actual = scene.height;
    ASSERT_EQ(expected, actual);

}

TEST(SceneViewTest, scene_width_matches_column_count_of_background_when_printed)
{
    SceneView scene(valid_background_scene);
    int expected = expected_scene_width;
    int actual = scene.width;
    ASSERT_EQ(expected, actual);
}

/* What should the yaml list look like?
 * Avoid premature refactor, just follow TDD guidelines...
 * Should be able to...
 * > add new thing to scene
 * > list all the "things" on the scene
 * > remove a specific thing from the scene
 * > update a thing on the scene */


TEST(SceneViewTest, print_an_individual_character_from_scene_using_coordinates)
{
    SceneView scene(valid_background_scene);
    char* actual = scene.print({18,2});
    char expected = 'T';
    ASSERT_EQ(expected, *actual);
    actual = scene.print({25,2});
    expected = 'E';
    ASSERT_EQ(expected, *actual);
    actual= scene.print({33,2});
    expected = 'S';
    ASSERT_EQ(expected, *actual);
    actual= scene.print({38,2});
    expected = 'T';
    ASSERT_EQ(expected, *actual);
}

TEST(SceneViewTest, attempting_to_print_invalid_coordinate_throws_exception)
{
    EXPECT_THROW(
        {SceneView scene(invalid_background_with_newlines_on_different_columns);},
        std::invalid_argument
    );
}

//TEST(SceneViewTest, todo)
//{
//    FAIL();
//}
