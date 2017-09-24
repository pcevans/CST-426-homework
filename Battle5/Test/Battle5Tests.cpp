//Dirty flag design pattern tests
#include <iostream>
#include "../Project/Battle5.h"

int main(void) {

	std::cout << "Creating scene objects..." << std::endl;
	Object hole(0), log(1), branch(2), bump(3), frog(4), tail(5), speck(6), fleck(7);
	Object sceneObjects[8] = { hole, log, branch, bump, frog, tail, speck, fleck };

	std::cout << "Linking objects in hierarchical pattern..." << std::endl << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (i != 0)
			sceneObjects[i].parent = &sceneObjects[i - 1];
		if (i != 7)
			sceneObjects[i].child = &sceneObjects[i + 1];
	}

	std::cout << "Parents' primary values are added together to get child's derived value." << std::endl << std::endl;


	std::cout << "Initial values:" << std::endl;
	std::cout << "Scene object primary values: " << std::endl;
	for (int i = 0; i < 8; i++) {
		std::cout << i << ": " << sceneObjects[i].getPrimaryData() << std::endl;
	}
	std::cout << "Scene object derived values: " << std::endl;
	for (int i = 0; i < 8; i++) {
		std::cout << i << ": " << sceneObjects[i].getDerivedData() << std::endl;
	}
	std::cout << std::endl;


	for (int i = 0; i < 10; i++) {
		std::cout << "Moving objects " << i % 8 << ", " << (i+3) % 8 <<", and " << (i+5) % 8 << std::endl;
		sceneObjects[i % 8].Move();
		sceneObjects[(i + 3) % 8].Move();
		sceneObjects[(i + 5) % 8].Move();

		std::cout << "Scene object primary values: " << std::endl;
		for (int i = 0; i < 8; i++) {
			std::cout << i << ": " << sceneObjects[i].getPrimaryData() << std::endl;
		}


		for (int i = 0; i < 8; i++)
			if (sceneObjects[i].dirty)
				sceneObjects[i].RecalculateData();

		std::cout << "Scene object derived values: " << std::endl;
		for (int i = 0; i < 8; i++) {
			std::cout << i << ": " << sceneObjects[i].getDerivedData() << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << "Press ENTER to quit." << std::endl;
	std::cin.get();

	return 0;

}