#ifndef Player_h
#define Player_h
#include "GameObject.h"

class Player : public Engine::GameObject
{
public:
	//Constructor, sets health and position
	Player() : Engine::GameObject(0, 0), m_health(1), m_name(nullptr) {}

	//Destructor
	~Player();

	//Accessors
	bool isAlive() const;
	char* getName() const;

	//Modifiers
	void setName(char* name);
	virtual void move(char dir);
	void takeDamage();

private:
	int m_health;
	char* m_name;

};

#endif /* Player_h */
