#include "GameEntity.h"

/* A container class that represents a Stack of GameEntities */
class GameEntityStack{
    public:
        GameEntityStack(int max_entity_count);
        ~GameEntityStack();
        /* Add a new entity to the stack */
        GameEntity add(GameEntity new_entity);
        /* Get an individual entity by index */
        GameEntity get(int idx);
        /* Update a particular entity by id */
        GameEntity update(int idx, GameEntity updated_entity);
        /* Returns max number of entites that can be added to the stack */
        int max_count();
        /* Returns the number of entities curently on the stack */
        int count();
    private:
        GameEntity* _game_entity_buffer{};
        int _max_entity_count{};
        int _entity_counter{};
        void _allocate_stack(int stack_size);
        void _deallocate_stack();
};
