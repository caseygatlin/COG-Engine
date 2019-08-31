#ifndef Game_h
#define Game_h

class Player;
class Monster;

class Game
{
public:
	//Constructor
	Game(int numMonsters);

	//Destructor
	~Game();

	//Methods for play
	void play();
	void checkCollision(Player* player, Monster* monster);
	void addMonster(Monster* clone);


private:
	int m_numMonsters;

	//Game entities
	Player* m_player;
	Monster** m_monsters;
};

#endif /* Game_h */
