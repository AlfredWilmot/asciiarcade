#include <cstdlib>
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
    return GameEntity{};
};

bool GameEntityStack::update(int id, GameEntity updated_entity)
{
    return false;
};
