//Service Locator design pattern
#include <iostream>

class Service {
public:
	virtual void startComponent(int id) = 0;
	virtual void stopComponent(int id) = 0;
	virtual void stopAllComponents() = 0;
	virtual void printActiveComponents() = 0;
};

class NormalService : public Service {
private:
	bool servarray[20];

public:
	NormalService() {
		for (int i = 0; i < 20; i++)
			servarray[i] = false;
	}

	void startComponent(int id) {
		if (id < 20)
			servarray[id] = true;
	}

	void stopComponent(int id) {
		if (id < 20)
			servarray[id] = false;
	}

	void printActiveComponents() {
		for (int i = 0; i < 20; i++)
			if (servarray[i] == true)
				std::cout << "Component " << i << " is on" << std::endl;
	}

	void stopAllComponents() {
		for (int i = 0; i < 20; i++)
			servarray[i] = false;
	}
};

class OtherService : public Service {
private:
	int servarray[20];
	int activecount;

public:
	OtherService() {
		for (int i = 0; i < 20; i++)
			servarray[i] = 0;
		activecount = 0;
	}

	void startComponent(int id) {
		if (id < 20 && servarray[id] == 0)
			servarray[id] = ++activecount;
	}

	void stopComponent(int id) {
		if (id < 20)
		{
			servarray[id] = 0;
			activecount--;
		}
	}

	void printActiveComponents() {
		for (int i = 0; i < 20; i++)
			if (servarray[i] > 0)
				std::cout << "Component " << i << " is priority "<< servarray[i] << std::endl;
	}

	void stopAllComponents() {
		for (int i = 0; i < 20; i++)
			servarray[i] = false;
	}
};

class ServiceLocator {

public:
	static void attachService(Service* newserv) { serv = newserv; }
	static Service* getService() { return serv; }

private:
	static Service* serv;
};

Service* ServiceLocator::serv = nullptr;
