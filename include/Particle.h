/* Represents an entity that can be presented by the scene */
struct Cartesian {
    float x{};
    float y{};
};

struct Particle{
    Cartesian position{};
    Cartesian velocity{};
    Cartesian acceleration{};
    float mass{};
};
