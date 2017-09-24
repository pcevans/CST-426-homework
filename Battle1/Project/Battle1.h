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
	{
		std::cout << "Creating gun spawner..." << std::endl;
	}

	Gun* spawnGun()
	{
		return proto->clone();
	}
};

class PotatoGun : public Gun {

public:
	PotatoGun()
		: Gun(10, 1)
	{
		std::cout << "Creating default potato gun..." << std::endl;
	}
	PotatoGun(int initrounds)
		: Gun(initrounds, 1)
	{
		std::cout << "Creating custom potato gun..." << std::endl;
	}
	Gun* clone()
	{
		std::cout << "Creating potato gun clone..." << std::endl;
		return new PotatoGun(numrounds);
	}
};

class NerfGun : public Gun {

public:
	NerfGun()
		: Gun(20, 3)
	{
		std::cout << "Creating default nerf gun..." << std::endl;
	}
	NerfGun(int initrounds)
		: Gun(initrounds, 3)
	{
		std::cout << "Creating custom nerf gun..." << std::endl;
	}
	Gun* clone()
	{
		std::cout << "Creating nerf gun clone..." << std::endl;
		return new NerfGun(numrounds);
	}
};

class BBGun : public Gun {

public:
	BBGun()
		: Gun(20, 5)
	{
		std::cout << "Creating default BB gun..." << std::endl;
	}
	BBGun(int initrounds)
		: Gun(initrounds, 5)
	{
		std::cout << "Creating custom BB gun..." << std::endl;
	}
	Gun* clone()
	{
		std::cout << "Creating BB gun clone..." << std::endl;
		return new BBGun(numrounds);
	}
};

class PaintballGun : public Gun {

public:
	PaintballGun()
		: Gun(5, 10)
	{
		std::cout << "Creating default paintball gun..." << std::endl;
	}
	PaintballGun(int initrounds)
		: Gun(initrounds, 10)
	{
		std::cout << "Creating custom paintball gun..." << std::endl;
	}
	Gun* clone()
	{
		std::cout << "Creating paintball gun clone..." << std::endl;
		return new PaintballGun(numrounds);
	}
};