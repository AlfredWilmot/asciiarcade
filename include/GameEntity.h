/* Represents a point in space */
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

/* Represents unique entity that can be represented in the Scene */
struct GameEntity{
    int uid{}; // ID associated with this particular entity
    int gid{}; // ID associating this entity with some wider entity group
    Particle info{};
};
