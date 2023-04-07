#include <3ds.h>
#include <stdio.h>
#include <iostream>

#include "color.h" // Include the header file


int main(int argc, char **argv)
{
	gfxInitDefault();
	PrintConsole topScreen, bottomScreen;
	consoleInit(GFX_TOP, &topScreen);
	consoleInit(GFX_BOTTOM, &bottomScreen);

	// Setup components of the script.
	Foreground FORE;
	Background BACK;
	Reset RESET;
	Move MOVE;

	consoleSelect(&topScreen);
	// Usage of Background
	std::cout << "-- Background --\n" << std::endl;
	std::cout << BACK.black << "Black" << std::endl;
	std::cout << BACK.red << "Red" << std::endl;
	std::cout << BACK.green << "Green" << std::endl;
	std::cout << BACK.yellow << "Yellow" << std::endl;
	std::cout << BACK.blue << "Blue" << std::endl;
	std::cout << BACK.magenta << "Magenta" << std::endl;
	std::cout << BACK.cyan << "Cyan" << std::endl;
	std::cout << BACK.white << FORE.black << "White" << std::endl;

	// Usage of Reset
	std::cout << RESET.reset << std::endl;

	// Usage of Foreground
	std::cout << "-- Foreground --\n" << std::endl;
	std::cout << FORE.black << BACK.white << "Black" << RESET.reset << std::endl;
	std::cout << FORE.red << "Red" << std::endl;
	std::cout << FORE.green << "Green" << std::endl;
	std::cout << FORE.yellow << "Yellow" << std::endl;
	std::cout << FORE.blue << "Blue" << std::endl;
	std::cout << FORE.magenta << "Magenta" << std::endl;
	std::cout << FORE.cyan << "Cyan" << std::endl;
	std::cout << FORE.white << "White" << std::endl;

	std::cout << "----------------\n" << std::endl;

	// Usage of Move.goTo
	std::cout << MOVE.goTo(30, 0) << FORE.red << "-------------- Press START to exit --------------" << RESET.reset;

	consoleSelect(&bottomScreen);
	std::cout << "This is a demo of " << FORE.red << "nfoert's" << RESET.reset << " simple color" << std::endl;
	std::cout << "library." << std::endl;
	std::cout << "\nI hope it's helpful!" << std::endl;
	std::cout << FORE.blue << MOVE.goTo(30, 0) << "https://github.com/nfoert/3dscolor ----";

	gfxFlushBuffers();
	gfxSwapBuffers();

	while (aptMainLoop())
	{
		//Scan Inputs
		hidScanInput();
		u32 kDown = hidKeysDown();

		if (kDown & KEY_START)
			break;

	}

	// Exit services
	gfxExit();
	return 0;
}
