#include "GameEntity.h"

/* A container class that represents a Stack of GameEntities */
class GameEntityStack{
    public:
        GameEntityStack(int max_entity_count);
        ~GameEntityStack();
        /* Get an individual entity by index */
        GameEntity get(int idx);
        /* Update a particular entity by id */
        bool update(int id, GameEntity updated_entity);
    private:
        GameEntity* _game_entity_buffer{};
        int _max_entity_count{};
        int _entity_counter{};
};
