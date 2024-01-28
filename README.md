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

# Components (WIP)
The different parts of this software and how they relate to each other:
- `SceneView`
    - Presents the game-state as ASCII text.
- `GameState`:
    - represented to the user as ascii (or some alternative front-end)
    - consists of a collection of interrelated `GameEntites`
- `GameEntites`:
    - represent things in the game that can be:
        - static/dynamic, driven purely through interaction forces
        - agent-driven (ie. directed either by a user or NPC).
    - have a Universally Uniqe Identifier (uuid), so they can be individually referenced
    - are associated with other entities via a Group Identifier (gid)
    - exhibit a "state" represented by a particle
    - may contain other information, such as whether they're in a state of collision
- `Partice`:
    - represent point-masses with cartesian and kinematic components
    - can interact with other particles via collision models

# Notes
A basic `CMakeLists.txt` is implemented for managing building of this application. \
Currently incorporates the `googletest` unit-testing framework for TDD.
