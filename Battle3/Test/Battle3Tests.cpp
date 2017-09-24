//Prototype design pattern
#include <iostream>
#include "../Project/Battle3.h"

int main(void) {
	SomethingElse se1(10, "String1");
	SomethingElse se2(20, "String2");

	Something s1(se1);
	Something s2(se1);
	Something s3(se2);
	Something s4(se2);

	std::cout << "Instance 1: ";
	s1.print();
	std::cout << "Instance 2: ";
	s2.print();

	std::cout << "Modifying properties..." << std::endl;
	s1.modifyProperty(100);
	s2.modifyProperty(-10);
	std::cout << "Instance 1: ";
	s1.print();
	std::cout << "Instance 2: ";
	s2.print();

	std::cout << std::endl;

	std::cout << "Instance 1: ";
	s3.print();
	std::cout << "Instance 2: ";
	s4.print();

	std::cout << "Modifying properties..." << std::endl;
	for (int i = 0; i < 10; i++) {
		s3.modifyProperty(1);
		s4.modifyProperty(-1);
	}
	std::cout << "Instance 1: ";
	s3.print();
	std::cout << "Instance 2: ";
	s4.print();

	std::cout << "Press ENTER to quit." << std::endl;
	std::cin.get();


}
