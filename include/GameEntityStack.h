#include "GameEntity.h"

/* A container class that represents a Stack of GameEntities */
class GameEntityStack{
    public:
        GameEntityStack(int entity_count);
        ~GameEntityStack();
        /* Get an individual by id */
        GameEntity get(int id);
        /* Get a list of entites associated by group-id */
        const GameEntity* group_get(int gid);
        /* Update a particular entity by id */
        bool update(int id, GameEntity updated_entity);
    private:
        GameEntity* _game_entity_buffer{};
};
