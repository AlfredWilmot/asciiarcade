#include <cstddef>
#include <cstdlib>
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
    this->_stack=(GameEntity*)calloc(stack_size+1, sizeof(Particle));
};
void GameEntityStack::_deallocate_stack()
{
    if(this->_stack!=NULL)
        free(this->_stack);
};

int GameEntityStack::add(Particle new_p)
{
    int uuid = 0;
    return uuid;
};

Particle GameEntityStack::get(int idx)
{
    return Particle{};
};

Particle GameEntityStack::update(int idx, Particle new_p)
{
    return Particle{};
};
