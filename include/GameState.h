struct Cartesian {
    float x{};
    float y{};
};

/* A generic representation of the smallest-unit of thing */
struct Particle{
    Cartesian position{};
    Cartesian velocity{};
    Cartesian acceleration{};
    float mass{};
};

/* Represents unique entity that can be presented by the GameState */
struct GameEntity{
    int uid{}; // ID associated with this particular entity
    int gid{}; // ID associating this entity with some wider entity group
    Particle info{};
};

/* A container class that represents a GameState */
// - Essentially a stack of GameEntities that can be randomly accessed.
class GameState{
    public:
        GameState(int entity_count);
        ~GameState();
        /* Get an individual by id */
        GameEntity get(int id);
        /* Get a list of entites associated by group-id */
        const GameEntity* group_get(int gid);
        /* Update a particular entity by id */
        bool update(int id, GameEntity updated_entity);
    private:
        GameEntity* _game_entity_buffer{};
};
