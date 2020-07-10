# u1274838

Gameplay: 
    The player must survive as long as possible by moving their ship around to avoid flying asteroids.
    Hitting an asteroid will cause the ship to lose health and the game to end. After the game is over,
    close the window and restart the game to try again.

Controls: 
    W-A-S-D for ship movement
    
Engine Code:
    I'm particularly proud of my development of the component system that we started creating last semester.
    Smart and Weak pointers are used when attaching, creating, and updating components, as well as accessing
    component-specific functions. The PlayerControllerComponent is created and added to a spawned GameObject
    when a JSON file has a "Player" controller type specified. 
        
        See:
        Engine/Components/Public/PlayerControllerComponent
        Engine/Spawning/Private/ObjectSpawner (SpawnCollideable function)
        Engine/Physics/Collision/Private/Collision (Controller handling)
    
    The HealthComponent keeps track of health and can be used in conjunction with the collision system to reduce
    health
    
        See:
        Engine/Components/Public/HealthComponent
        Gamecode/PlayerShip/Private/PlayerShipSpawner (Attached when spawning and linked with collision in OnCollision)
        
    I feel like the component system integrates most engine features together into one system nicely and provides a useful
    interface for creating new components for future games.
