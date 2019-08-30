#ifndef Game_h
#define Game_h

class Player;
class Monster;

class Game
{
public:
	Game(int numMonsters, int rows, int columns);
	~Game();

	void play();
	void checkCollision(Player* player, Monster* monster);


private:
	int m_numMonsters;
	int m_rows;
	int m_columns;
	int** m_field;

	Player* m_player;
	Monster** m_monsters;
};

#endif /* Game_h */
