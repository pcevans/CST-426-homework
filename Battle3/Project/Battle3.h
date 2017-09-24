//Type object
#include <iostream>

class SomethingElse {
private:
	int prop;
	const char* string;
public:
	SomethingElse(int initproperty, const char* initstring)
		: prop(initproperty),
		string(initstring)
	{}

	int getProperty() { return prop; }
	const char* getString() { return string; }
};

class Something {
private:
	SomethingElse& somethingelse;
	int prop;
public:
	Something(SomethingElse& se)
		: prop(se.getProperty()),
		somethingelse(se)
	{}

	const char* getString()
	{
		return somethingelse.getString();
	}

	void modifyProperty(int num)
	{
		prop += num;
	}

	void print() {
		std::cout << getString() << ", " << prop << std::endl;
	}
};