#ifndef Monster_h
#define Monster_h


class Monster
{
public:
	//Constructors, descructor, assignment operator
	Monster();
	Monster(const Monster& src, int lifetime = 0);
	Monster &operator=(const Monster& src);
	~Monster();

	//Accessors
	int row() const;
	int column() const;
	void printName() const;

	//In game modifiers
	bool isOlderAndLived();
	void setName();
	void move();

private:
	int m_lifetime;
	int m_row;
	int m_column;
	int m_nameLength;
	char* m_name;
};

#endif /* Monster_h */
