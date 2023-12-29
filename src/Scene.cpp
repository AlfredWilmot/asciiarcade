#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include "Scene.h"

Scene::Scene(const char* scene_background)
{
    if (this->_all_newlines_are_on_same_column(scene_background) == false)
        throw std::invalid_argument("Invalid scene, must be rectangular.");
    if (this->_number_of_chars_before_first_newline(scene_background) <= 0)
        throw std::invalid_argument("Invalid scene, must contain at least one newline.");

    this->_content_buffer=(char*)malloc(strlen(scene_background)*sizeof(char));
    strcpy(this->_content_buffer, scene_background);
};

Scene::~Scene()
{
    free(this->_content_buffer);
};

char * Scene::print(){
    std::cout << this->_content_buffer << std::endl;
    return this->_content_buffer;
};

int Scene::_number_of_chars_before_first_newline(const char* content_buffer){
    for (int i{}; i <= strlen(content_buffer); i++)
        if (content_buffer[i] == '\n')
            return i;
    return -1;
};

int Scene::_total_number_of_newlines(const char* content_buffer){
    int newline_count{};
    for (int i=1; i < strlen(content_buffer)+1; i++)
        if (content_buffer[i] == '\n')
            newline_count++;
    return newline_count;
};

bool Scene::_all_newlines_are_on_same_column(const char* content_buffer){
    int previous_line_char_count=0;
    int current_line_char_count=0;
    for (int i{}; i <= strlen(content_buffer); i++)
    {
        if (content_buffer[i] == '\n')
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
