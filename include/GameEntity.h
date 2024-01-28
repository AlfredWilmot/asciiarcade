/* Represents a coordinate in space */
struct Cartesian {
    float x{};
    float y{};
};

/* A generic representation of the smallest-unit of thing */
struct Particle{
    float mass{};
    Cartesian position{};
    Cartesian velocity{};
    Cartesian acceleration{};
};

/* Represents unique entity that can be represented in the Scene */
struct GameEntity{
    int uuid = 0;                 // Universally Unique ID of this particular entity
    int gid{};                  // Unique group ID of this entity's posse
    Particle physical_state{};  // This entity's physical attributes
}; 
