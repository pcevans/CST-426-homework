//Prototype design pattern
#include <iostream>

class Gun {
protected:
	int numrounds;
	int hitdamage;
public:
	Gun(int initRounds, int initdamage)
		: numrounds(initRounds), hitdamage(initdamage)
	{}
	virtual ~Gun() {}
	virtual Gun* clone() = 0;
	void shoot() {
		numrounds--;
	}
	void print() 
	{
		std::cout << "Number of rounds: " << numrounds << ", damage on hit: " << hitdamage << std::endl;
	}
};

class Spawner
{
private:
	Gun* proto;

public:
	Spawner(Gun* prototype)
		: proto(prototype)
	{}

	Gun* spawnGun()
	{
		return proto->clone();
	}
};

class PotatoGun : public Gun {

public:
	PotatoGun()
		: Gun(10, 1)
	{}
	PotatoGun(int initrounds)
		: Gun(initrounds, 1)
	{}
	Gun* clone()
	{
		return new PotatoGun(numrounds);
	}
};

class NerfGun : public Gun {

public:
	NerfGun()
		: Gun(20, 3)
	{
	}
	NerfGun(int initrounds)
		: Gun(initrounds, 3)
	{
	}
	Gun* clone()
	{
		return new NerfGun(numrounds);
	}
};

class BBGun : public Gun {

public:
	BBGun()
		: Gun(20, 5)
	{
	}
	BBGun(int initrounds)
		: Gun(initrounds, 5)
	{
	}
	Gun* clone()
	{
		return new BBGun(numrounds);
	}
};

class PaintballGun : public Gun {

public:
	PaintballGun()
		: Gun(5, 10)
	{
	}
	PaintballGun(int initrounds)
		: Gun(initrounds, 10)
	{
	}
	Gun* clone()
	{
		return new PaintballGun(numrounds);
	}
};