#ifndef Game_h
#define Game_h
#include "Character.h"

class Game
{
public:
	//Constructor
	explicit Game(int numMonsters);

	//Copy constructor
	Game(const Game& src);

	//Assignment operator
	Game& operator=(const Game& src);

	//Destructor
	~Game();

	//Methods for play
	void play();
	void setName(Engine::Character* characterObj);
	void addMonster(Engine::Character* monsterClone);


private:
	int m_numMonsters;

	//Game entities
	Engine::Character* m_player;
	Engine::Character** m_monsters; //An array of monsters
};

#endif /* Game_h */
