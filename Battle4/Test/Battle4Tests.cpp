//Service locator design pattern tests
#include <iostream>
#include "../Project/Battle4.h"

int main(void) {

	std::cout << "Creating services..." << std::endl << std::endl;
	Service* normalservice = new NormalService();
	Service* otherservice = new OtherService();
	//random list of component indices to turn on inside service
	int compidxlist[10] = { 19, 5, 3, 16, 0, 4, 3, 6, 10, 9 };

	for (int i = 0; i < 2; i++)
	{
		if (i == 1) {
			std::cout << "Using service \"OtherService\"..." << std::endl;
			ServiceLocator::attachService(otherservice);
		}
		else {
			std::cout << "Using service \"NormalService\"..." << std::endl;
			ServiceLocator::attachService(normalservice);
		}

		Service* activeservice = ServiceLocator::getService();
		std::cout << "Starting service components..." << std::endl;
		for (int i = 0; i < 10; i++) {
			activeservice->startComponent(compidxlist[i]);
		}
		std::cout << "Active service components:" << std::endl;
		activeservice->printActiveComponents();
		std::cout << "Stopping all service components..." << std::endl;
		activeservice->stopAllComponents();
		std::cout << "Active service components:" << std::endl;
		activeservice->printActiveComponents();
		std::cout << std::endl;
	}


	std::cout << "Press ENTER to quit." << std::endl;
	std::cin.get();

	return 0;
}

