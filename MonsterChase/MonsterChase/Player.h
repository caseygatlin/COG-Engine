#ifndef Player_h
#define Player_h

class Player
{
public:
	//Constructor
	Player();

	//Destructor
	~Player();

	//Accessors
	int row() const;
	int column() const;
	bool isAlive() const;
	void printName() const;

	//In game modifiers
	void setName();
	void move(char dir);
	void loseHealth();

private:
	int m_row;
	int m_column;
	int m_health;
	char* m_name;

};

#endif /* Player_h */
