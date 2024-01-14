#include <tuple>
#pragma once

/* Uses the inputted ASCII string to represent the game-state
 * The "Scene" has no concept of the entites contained within,
 * it merely shows what's there.
 */
class Scene{

    public:
        /* Associates a buffer of ascii content to the scene instance */
        Scene(const char* scene_background);

        /* Release memory-block used to store the scene when the show is done */
        ~Scene();

        /* Dumps contents of scene onto the display */

            // print entire scene
            char* print();
            // print an individual character from scene
            char* print(std::tuple<int, int> coord);
            // print a "region-of-interest" (ROI) from scene
            char* print(std::tuple<int, int> coord_0, std::tuple<int, int> coord_1);

        /* Scene attribute getter methods */
        int height;
        int width;

    private:
        /* All characters that constitute the scene (including escape characters) */
        char* _scene_contents{};

        /* Determines scene width */
        int _number_of_chars_before_first_newline(const char*);

        /* Determines scene height */
        int _total_number_of_newlines(const char*);

        /* Validates that content buffer forms a rectangular scene */
        bool _all_newlines_are_on_same_column(const char*);

        /* Converts an (x,y) coordinate to the equivalent content_buffer index */
        int _coord_to_buffer_index(int x, int y);
};
