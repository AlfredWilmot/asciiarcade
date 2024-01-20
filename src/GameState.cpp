#include <cstdlib>
#include <stdexcept>
#include "GameEntityStack.h"

GameEntityStack::GameEntityStack(int max_entity_count)
{
    this->_allocate_stack(max_entity_count);
}
GameEntityStack::~GameEntityStack()
{
    this->_deallocate_stack();
};

void GameEntityStack::_allocate_stack(int stack_size)
{
    if (stack_size < 1) {
        throw std::invalid_argument("Allocated stack-size must exceed 0");
    }
    this->_max_entity_count=stack_size;
    this->_game_entity_buffer=(GameEntity*)calloc(stack_size+1, sizeof(GameEntity));
};
void GameEntityStack::_deallocate_stack()
{
    if(this->_game_entity_buffer!=NULL)
        free(this->_game_entity_buffer);
};

GameEntity GameEntityStack::add(GameEntity new_entity)
{
    if (this->count() < this->max_count()) {
        this->_entity_counter+=1;
        this->_game_entity_buffer[this->count()] = new_entity;
    }
    else {
        throw std::invalid_argument("Stack is full.");
    }
    return this->_game_entity_buffer[this->count()];
};
GameEntity GameEntityStack::get(int idx)
{
    return GameEntity{};
};

GameEntity GameEntityStack::update(int idx, GameEntity updated_entity)
{
    return GameEntity{};
};

int GameEntityStack::max_count()
{
    return this->_max_entity_count;
};

int GameEntityStack::count()
{
    return this->_entity_counter;
};
