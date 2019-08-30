#ifndef Monster_h
#define Monster_h


class Monster
{
public:
	Monster();
	~Monster();

	int row() const;
	int column() const;
	bool isOlderAndLived();
	void setName();
	void printName() const;

	void move();

private:
	int m_lifetime;
	int m_row;
	int m_column;
	char* m_name;
};

#endif /* Monster_h */
