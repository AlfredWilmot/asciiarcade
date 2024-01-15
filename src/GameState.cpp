#include <cstdlib>
#include "GameState.h"

/* A container class that represents a GameState */
// - Essentially a stack of GameEntities that can be randomly accessed.
GameState::GameState(int entity_count)
{
    this->_game_entity_buffer=
        (GameEntity*)calloc(entity_count, sizeof(GameEntity));
}

GameState::~GameState()
{
    if(this->_game_entity_buffer!=NULL)
        free(this->_game_entity_buffer);
};

GameEntity GameState::get(int id)
{
    return GameEntity{};
};

const GameEntity* GameState::group_get(int gid)
{
    return nullptr;
};

bool GameState::update(int id, GameEntity updated_entity)
{
    return false;
};
