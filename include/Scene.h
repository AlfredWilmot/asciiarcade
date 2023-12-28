#pragma once

class Scene {

    public:
        /* Associates a buffer of ascii content to the scene instance */
        Scene(const char* scene_content_buffer);

        /* Dumps contents of scene onto the display */
        void print();

        /* Scene attribute getter methods */
        int height(){return _total_number_of_newlines();};
        int width(){return _number_of_chars_before_first_newline();};

    private:
        /* All characters that constitute the scene (including escape characters) */
        char* _content_buffer{};

        /* Determines scene width */
        int _number_of_chars_before_first_newline();

        /* Determines scene height */
        int _total_number_of_newlines();
};
