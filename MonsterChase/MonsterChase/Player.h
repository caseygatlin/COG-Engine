#ifndef Player_h
#define Player_h

class Player
{
public:
	Player();
	~Player();

	int row() const;
	int column() const;
	bool isAlive() const;

	void setName();
	void printName() const;

	void move(char dir);
	void loseHealth();



private:
	int m_row;
	int m_column;
	int m_health;
	char* m_name;

};

#endif /* Player_h */
