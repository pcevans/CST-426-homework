//Prototype design pattern
#include <iostream>
#include "../Project/Battle4.h"

int main(void) {

	Service* normalservice = new NormalService();
	Service* otherservice = new OtherService();
	int servicelist[10] = { 19, 5, 3, 16, 0, 4, 3, 6, 10, 9 };

	for (int i = 0; i < 2; i++)
	{
		if (i == 1)
			ServiceLocator::attachService(otherservice);
		else
			ServiceLocator::attachService(normalservice);

		Service* activeservice = ServiceLocator::getService();
		for (int i = 0; i < 10; i++) {
			activeservice->startComponent(servicelist[i]);
		}
		activeservice->printActiveComponents();
		activeservice->stopAllComponents();
		activeservice->printActiveComponents();
		std::cout << std::endl;
	}


	std::cout << "Press ENTER to quit." << std::endl;
	std::cin.get();

	return 0;
}

