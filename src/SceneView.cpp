#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include "SceneView.h"

SceneView::SceneView(const char* scene_background)
{
    if (this->_all_newlines_are_on_same_column(scene_background) == false)
        throw std::invalid_argument("Invalid scene, must be rectangular.");
    if (this->_number_of_chars_before_first_newline(scene_background) <= 0)
        throw std::invalid_argument("Invalid scene, must contain at least one newline.");

    /* Allocating memory to background, and copying contents; don't forget the trailing '\0'! */
    this->_scene_contents=(char*)malloc(strlen(scene_background)*sizeof(char)+1);
    strcpy(this->_scene_contents, scene_background);

    /* Storing background dimensions when scene is initialized */
    this->height=_total_number_of_newlines(this->_scene_contents);
    this->width=_number_of_chars_before_first_newline(this->_scene_contents);
};

SceneView::~SceneView()
{
    if(this->_scene_contents != NULL)
        free(this->_scene_contents);
};

int SceneView::_coord_to_buffer_index(int x, int y){
    return y*(this->width+1)+x;
};

char* SceneView::print(){
    return this->_scene_contents;
};

char* SceneView::print(std::tuple<int, int> coord){
    int x = std::get<0>(coord);
    int y = std::get<1>(coord);
    return &this->_scene_contents[this->_coord_to_buffer_index(x, y)];
};

int SceneView::_number_of_chars_before_first_newline(const char* scene_contents){
    for (int i{}; i <= strlen(scene_contents); i++)
        if (scene_contents[i] == '\n')
            return i;
    return -1;
};

int SceneView::_total_number_of_newlines(const char* scene_contents){
    int newline_count{};
    for (int i=1; i < strlen(scene_contents)+1; i++)
        if (scene_contents[i] == '\n')
            newline_count++;
    return newline_count;
};

bool SceneView::_all_newlines_are_on_same_column(const char* scene_contents){
    int previous_line_char_count=0;
    int current_line_char_count=0;
    for (int i{}; i <= strlen(scene_contents); i++)
    {
        if (scene_contents[i] == '\n')
        {
            if (previous_line_char_count != 0)
            {
                if (previous_line_char_count != current_line_char_count)
                    return false;
            };
            previous_line_char_count = current_line_char_count;
            current_line_char_count=0;
        }
        else
        {
            current_line_char_count+=1;
        };
    };
    return true;
};
