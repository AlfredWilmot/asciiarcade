#include "GameEntity.h"

// Defining an interface in c++ (i.e. "Protocol" or "ABC"/"Meta-class")?

/* A container class that represents a Stack of GameEntities */
class GameEntityStack{
    public:
        GameEntityStack(int max_entity_count);
        ~GameEntityStack();
        /* Returns the UUID of the particle added to the stack */
        int add(Particle new_p);
        /* Returns the entity corresponding to a uuid or coordinate */
        Particle  get(int uuid);
        Particle  get(int x, int y);
        /* Update a particular entity on the stack */
        Particle update(int idx, Particle new_p);
    private:

        GameEntity* _stack{};
        int _max_count{};
        int _counter{};
        void _allocate_stack(int stack_size);
        void _deallocate_stack();
};
