```
              _             _ _    _                      _      
             / \   ___  ___(_|_)  / \   _ __ ___ __ _  __| | ___ 
            / _ \ / __|/ __| | | / _ \ | '__/ __/ _` |/ _` |/ _ \
           / ___ \\__ \ (__| | |/ ___ \| | | (_| (_| | (_| |  __/
          /_/   \_\___/\___|_|_/_/   \_\_|  \___\__,_|\__,_|\___|
          
                  ___________________________________ 
                 / A game-engine that represents the \
                 \ game-state using ASCII text       /
                  ----------------------------------- 
                         \   ^__^
                          \  (oo)\_______
                             (__)\       )\/\
                                 ||----w |
                                 ||     ||            
```

# Components
The different parts of this software and how they relate to each other.

## `Scene`
An interface that exposes a basic CRUD-style API to the client to interact
with entities presented by the scene. Presents the game-state as ASCII text.

## CMake
A basic `CMakeLists.txt` is implemented for managing building of this application. \
Currently incorporates the `googletest` unit-testing framework for TDD.
