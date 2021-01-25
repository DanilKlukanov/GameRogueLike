#include <windows.h>
#include "curses/curses.h"
#include "GameElements/GameLoop.h"
#include "GameElements/GameMap.h"
#define _WIN32_WINNT 0x0500

int main()
{
	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
	initscr();
	noecho();
	curs_set(0);
	keypad(stdscr, true);
	nodelay(stdscr, true);
	GameLoop game;
	while (true) {
		game.Play();
		endwin();
		break;
	}
}

