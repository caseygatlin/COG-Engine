![EngineLogo](https://external-sjc3-1.xx.fbcdn.net/safe_image.php?d=AQCZyHYZhJO8ijBt&w=960&h=960&url=https%3A%2F%2Frepository-images.githubusercontent.com%2F278541113%2F3b55ec00-cfad-11ea-904f-27432adccd90&_nc_hash=AQCeYPpziC5bTVfx)

# The COG Engine

The COG Engine is a personally developed game engine for creating 2D games.
This project was programmed by myself with the help of open-source third-party libraries for sprite rendering, multithreading, and JSON file reading.

### Features:
- 2D sprite rendering
- 2D physics and collision
- Job system for use in multithreading
- Keyboard input handling
- Component system for adding functionality to GameObjects/Entities.
- Smart and Weak ptrs for managing objects across systems.
- JSON file reading for data-driven object creation.

# Asteroid Avoidance
To demonstrate the capabilities of the engine, I've developed a simple asteroid avoidance game, which plays when running the project file. Its source code is found in [this](https://github.com/caseygatlin/2D-Game-Engine/tree/master/MonsterChase/Gamecode) folder in the repository.

### Gameplay
The player must survive as long as possible by moving their ship around to avoid flying asteroids. Hitting an asteroid will cause the ship to lose health and the game to end. After the game is over, close the window and restart the game to try again.

### Controls
W-A-S-D for ship movement.

# Example Directories

A few notable examples of the work I've done can be found at these locations in the repository:
- **Component System** - The component system uses an interface class from which you can create custom components for `GameObjects`. Smart and Weak pointers are used when attaching, creating, and updating components, as well as accessing component-specific functions.
    - [Component System Directory](https://github.com/caseygatlin/2D-Game-Engine/tree/master/MonsterChase/Engine/Components/Public)
- **Data Driven Object Creation** - Object creation can be done by adding a JSON file containing the data for the object (mass, spawn position, texture file path, etc.) and spawning the object via the `ObjectSpawner`. In the Asteroid Avoidance example, this is done asynchronously through the job system.
    - [Example JSON Data](https://github.com/caseygatlin/2D-Game-Engine/tree/master/MonsterChase/Content)
    - [Object Spawning and JSON File Reading Directory](https://github.com/caseygatlin/2D-Game-Engine/tree/master/MonsterChase/Engine/Spawning)
- **Collision System** - The 2D collision system uses swept separating axis collision for checking collision and uses `std::function` for the collision response. Every frame the physics system checks for collisions and executes the callback for both `Collideables` if one is found.
    - [Collision System Directory](https://github.com/caseygatlin/2D-Game-Engine/tree/master/MonsterChase/Engine/Physics/Collision)

# Example File

- **Asteroid Spawner** - This `GameObject` spawns collideable asteroids asynchronously until the game ends, and is a good example of how all the core systems work together in the game.
    - [`AsteroidSpawner.cpp`](https://github.com/caseygatlin/2D-Game-Engine/blob/master/MonsterChase/Gamecode/Asteroids/Private/AsteroidSpawner.cpp)
