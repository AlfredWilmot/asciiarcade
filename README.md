# asciiarcade
A basic game-engine that uses ascii to represent the game state.

# Components
The different parts of this software and how they relate to each other.

## Scene
Represents the game-state to the client and exposes an API that enables the
addition of quantifiable entities into the scene. Each new entity
will be represented inernally via a dictionary (which will initially be stored
in non-volatile memory as a json file). The API will look something like this:
```cpp
Scene scene(background);
scene.add(ball_1);
scene.add(ball_2);
scene.list();
/*
    - uuid: "ball_1"
    - position:
        - x: 0
        - y: 0
    - velocity:
        - x: 0
        - y: 0
    - acceleration:
        - x: 0
        - y: 0
*/
```

## References
- https://ncona.com/2019/03/building-a-cpp-project-with-cmake/
