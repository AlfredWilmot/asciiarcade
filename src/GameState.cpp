#include <cstdlib>
#include <stdexcept>
#include "GameEntityStack.h"

GameEntityStack::GameEntityStack(int entity_count)
{
    this->_game_entity_buffer=
        (GameEntity*)calloc(entity_count, sizeof(GameEntity));
}

GameEntityStack::~GameEntityStack()
{
    if(this->_game_entity_buffer!=NULL)
        free(this->_game_entity_buffer);
};

GameEntity GameEntityStack::get(int idx)
{
    if (this->_entity_counter<=0) {
        throw std::invalid_argument("There are no entities in this stack!");
    }
    return GameEntity{};
};

bool GameEntityStack::update(int id, GameEntity updated_entity)
{
    return false;
};
