#ifndef Game_h
#define Game_h

namespace Engine
{
	class GameObject;
}

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
	void setName(Engine::GameObject* characterObj);
	void addMonster(Engine::GameObject* monsterClone);
	void updateMonsters();
	void updatePlayer(char& i_input);
	void statePlayerLocation() const;
	void getUserInput(char& o_input) const;
	void checkCollisions();

private:

	int						m_numMonsters;

	//Game entities
	Engine::GameObject*		m_player;
	Engine::GameObject**	m_monsters; //An array of monsters
};

#endif /* Game_h */
