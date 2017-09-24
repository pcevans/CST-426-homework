//Prototype design pattern
#include <iostream>
#include "../Project/Battle1.h"

int main(void) {
	//create potato gun prototype, spawner, and instance
	std::cout << "Creating default potato gun..." << std::endl;
	Gun* protopg = new PotatoGun();
	std::cout << "Prototype: ";
	protopg->print();

	std::cout << "Creating gun spawner..." << std::endl;
	Spawner pgspawner(protopg);

	std::cout << "Creating potato gun instance..." << std::endl;
	Gun* pginst = pgspawner.spawnGun();
	std::cout << "Instance: ";
	pginst->print();

	//shoot potato gun
	std::cout << "Shooting potato gun 10 times..." << std::endl;
	for(int i = 0; i < 10; i++)
		pginst->shoot();

	std::cout << "Comparing instance and prototype values..." << std::endl;
	//instance values should change while prototype values don't
	std::cout << "Instance: ";
	pginst->print();
	std::cout << "Prototype: ";
	protopg->print();
	std::cout << std::endl;

	//do same procedure for BB gun (prototype, spawner, instance, shoot, compare)
	std::cout << "Creating custom BB gun..." << std::endl;
	Gun* protobbg = new BBGun(1);
	protobbg->print();

	std::cout << "Creating gun spawner..." << std::endl;
	Spawner bbgspawner(protobbg);

	std::cout << "Creating BB gun instance..." << std::endl;
	Gun* bbginst = bbgspawner.spawnGun();
	bbginst->print();

	std::cout << "Shooting BB gun once..." << std::endl;
	bbginst->shoot();

	std::cout << "Comparing instance and prototype values..." << std::endl;
	std::cout << "Instance: ";
	bbginst->print();
	std::cout << "Prototype: ";
	protobbg->print();
	std::cout << std::endl;

	std::cout << "Press ENTER to quit." << std::endl;
	std::cin.get();

	return 0;
}

