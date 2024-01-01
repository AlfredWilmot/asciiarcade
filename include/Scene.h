#include <tuple>
#pragma once

/* Presents the game-state via ASCII text */
class Scene {

    public:
        /* Associates a buffer of ascii content to the scene instance */
        Scene(const char* scene_background);

        /* Release memory-block used to store the scene when the show is done */
        ~Scene();

        /* Dumps contents of scene onto the display */
        char* print(std::tuple<int, int> coord={});

        /* Returns the total number of objects added to the scene */
        int count();

        /* adds a new thing to the scene */
        void add(const char* thing);

        /* gets the last thing that was added to the scene */
        const char* pop();

        /* Scene attribute getter methods */
        int height(){return _total_number_of_newlines(this->_scene_contents);};
        int width(){return _number_of_chars_before_first_newline(this->_scene_contents);};

    private:
        /* All characters that constitute the scene (including escape characters) */
        char* _scene_contents{};

        /* tracks the number of entities that have been added to the scene */
        int _entity_counter{};

        /* Determines scene width */
        int _number_of_chars_before_first_newline(const char*);

        /* Determines scene height */
        int _total_number_of_newlines(const char*);

        /* Validates that content buffer forms a rectangular scene */
        bool _all_newlines_are_on_same_column(const char*);
};
