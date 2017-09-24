//Prototype design pattern
#include <iostream>
#include "../Project/Battle1.h"

int main(void) {
	//create potato gun prototype and spawner
	Gun* protopg = new PotatoGun(30);
	std::cout << "Prototype: ";
	protopg->print();
	Spawner pgspawner(protopg);

	//spawn an instance of potato gun
	Gun* pginst = pgspawner.spawnGun();
	std::cout << "Instance: ";
	pginst->print();

	//shoot potato gun
	for(int i = 0; i < 10; i++)
		pginst->shoot();

	//instance values should change while prototype values don't
	std::cout << "Instance: ";
	pginst->print();
	std::cout << "Prototype: ";
	protopg->print();
	std::cout << std::endl;

	//do same procedure for BB gun (prototype, spawner, instance, shoot, compare)
	Gun* protobbg = new BBGun(1);
	protobbg->print();
	Spawner bbgspawner(protobbg);
	Gun* bbginst = bbgspawner.spawnGun();
	bbginst->print();

	bbginst->shoot();
	std::cout << "Instance: ";
	bbginst->print();
	std::cout << "Prototype: ";
	protobbg->print();
	std::cout << std::endl;

	std::cout << "Press ENTER to quit." << std::endl;
	std::cin.get();

	return 0;
}

