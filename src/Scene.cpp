#include <cstdlib>
#include <cstring>
#include <iostream>
#include "Scene.h"

Scene::Scene(const char* scene_content_buffer)
{
    this->_content_buffer=(char*)malloc(strlen(scene_content_buffer)*sizeof(char));
    strcpy(this->_content_buffer, scene_content_buffer);
};

void Scene::print(){
    std::cout << this->_content_buffer << std::endl;
};

int Scene::_number_of_chars_before_first_newline(){
    for (int i{}; i <= strlen(this->_content_buffer); i++)
        if (this->_content_buffer[i] == '\n')
            return i;
    return -1;
};

int Scene::_total_number_of_newlines(){
    int newline_count{};
    for (int i=1; i < strlen(this->_content_buffer)+1; i++)
        if (this->_content_buffer[i] == '\n')
            newline_count++;
    return newline_count;
};
