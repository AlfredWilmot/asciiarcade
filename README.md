# asciiarcade
A basic game-engine that uses ascii to represent the game state.

# Components
The different parts of this software and how they relate to each other.

## Scene
An interface that exposes a basic CRUD-style API to the client to interact
with entities presented by the scene. Presents the game-state as ASCII text.

## References
- https://ncona.com/2019/03/building-a-cpp-project-with-cmake/

## CMake
A basic `CMakeLists.txt` is implemented for managing building of this application.
Currently incorporates the `googletest` unit-testing framework for TDD.
