#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include "GameEntityStack.h"

GameEntityStack::GameEntityStack(int max_count)
{
    this->_allocate_stack(max_count);
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
    this->_max_count=stack_size;
    this->_stack=(Particle*)calloc(stack_size+1, sizeof(Particle));
};
void GameEntityStack::_deallocate_stack()
{
    if(this->_stack!=NULL)
        free(this->_stack);
};

Particle* GameEntityStack::add(Particle new_p)
{
    if (this->_is_position_occupied(new_p.position)) {
        throw std::invalid_argument("Invalid Particle, position is already occupied");
    };
    if (this->_counter < this->_max_count) {
        this->_stack[this->_counter] = new_p;
        this->_counter+=1;
        return &this->_stack[this->_counter-1];
    }
    throw std::overflow_error("Stack is full!");
};

bool GameEntityStack::_is_position_occupied(Cartesian pos)
{
    for (size_t i{}; i<this->_counter; i++) {
        if (
            this->_stack[i].position.x == pos.x &&
            this->_stack[i].position.y == pos.y
        ) {
            return true;
        };
    };
    return false;
};

Particle GameEntityStack::get(int idx)
{
    return Particle{};
};

Particle GameEntityStack::update(int idx, Particle new_p)
{
    return Particle{};
};
