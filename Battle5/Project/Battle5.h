//Dirty flag design pattern
#include <iostream>

//object has primary data and derived data
//derived data is all parents' primary data added together
//dirty flag is true when this derived data needs to be recalculated
class Object {
private:
	int deriveddata;
	int primarydata;
public:
	Object* parent;
	Object* child;
	bool dirty;

	Object()
		: primarydata(0), dirty(true)
	{}

	Object(int initdata)
		: primarydata(initdata), dirty(true)
	{}

	void Move()
	{
		primarydata += 1;
		dirty = true;
		Object* tempchild = child;
		while (tempchild != nullptr) {
			tempchild->dirty = true;
			tempchild = tempchild->child;
		}
	}

	int CalculateData() 
	{
		if (parent == nullptr)
			return primarydata;
		if (parent->dirty)
			parent->RecalculateData();
		return parent->getDerivedData() + primarydata;
	}

	void RecalculateData() {
		deriveddata = CalculateData();
		dirty = false;
	}

	int getPrimaryData() {
		return primarydata;
	}

	int getDerivedData() {
		return deriveddata;
	}
};