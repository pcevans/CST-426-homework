//Game loop design pattern
#include <iostream>
#include <conio.h>

//GameLoop class will encapsulate a running game
class GameLoop {
private:
	int dirx;
	int diry;
	int posx;
	int posy;
	int running;
public:
	GameLoop()
		: dirx(0), diry(0), posx(0), posy(0), running(true)
	{}

	void run() {
		//print initial text
		std::cout << "Welcome to the game!" << std::endl;
		std::cout << "Press WASD to move." << std::endl;
		std::cout << "Press ESCAPE to quit." << std::endl;

		//run game loop
		while (running)
		{
			processInput();
			update();
			render();
		}
	}

	void processInput() {
		//check for new input
		//on WASD, change direction variables
		//on ESCAPE, change running boolean
		char input;
		while (_kbhit())
		{
			input = _getch();
			switch (input) {
			case 0x1B: //escape
				running = false;
				break;
			case 0x41: //A
				dirx = -1;
				diry = 0;
				break;
			case 0x61: //a
				dirx = -1;
				diry = 0;
				break;
			case 0x44: //D
				dirx = 1;
				diry = 0;
				break;
			case 0x64: //d
				dirx = 1;
				diry = 0;
				break;
			case 0x57: //W
				dirx = 0;
				diry = -1;
				break;
			case 0x77: //w
				dirx = 0;
				diry = -1;
				break;
			case 0x53: //S
				dirx = 0;
				diry = 1;
				break;
			case 0x73: //s
				dirx = 0;
				diry = 1;
				break;
			default: break;
			}
		}
	}

	void update() {
		//move character
		posx += dirx;
		posy += diry;

		//force character's position to be non-negative
		if (posx < 0)
			posx = 0;
		if (posy < 0)
			posy = 0;
	}

	void render() {
		//don't change screen until player starts playing
		if (!(dirx == 0 && diry == 0))
		{
			//clear console window
			system("cls");

			//go down appropriate number of lines
			for (int i = 0; i < posy; i++)
				std::cout << std::endl;

			//go across appropriate number of lines
			for (int i = 0; i < posx; i++)
				std::cout << " ";

			//place character
			std::cout << "X";
		}
	}
};