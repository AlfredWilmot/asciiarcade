#include <iostream>
#include <cstring>

class Scene {
    public:

        Scene(const char* scene_content_buffer){
            this->_content_buffer=(char*)malloc(strlen(scene_content_buffer)*sizeof(char));
            strcpy(this->_content_buffer, scene_content_buffer);
        };

        char* print(){return this->content_buffer();};
        int height(){return _total_number_of_newlines();};
        int width(){return _number_of_chars_before_first_newline();};

    protected:
        char* content_buffer(){
            return this->_content_buffer;
        };
    private:
        /* All characters that constitute the scene (including escape characters) */
        char* _content_buffer{};

        /* Determines scene width */
        int _number_of_chars_before_first_newline(){
            for (int i{}; i <= strlen(this->content_buffer()); i++)
                if (this->content_buffer()[i] == '\n')
                    return i;
            return -1;
        };

        /* Determines scene height */
        int _total_number_of_newlines(){
            int newline_count{};
            for (int i=1; i < strlen(this->content_buffer())+1; i++)
                if (this->content_buffer()[i] == '\n')
                    newline_count++;
            return newline_count;
        };
};
