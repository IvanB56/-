#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <locale>
#include <string>
#include <iomanip>
#include <vector>
#include <iterator>
#include <filesystem>
#include <sstream>

#include "Color.h"
#include "HardDisk.h"
#include "KeyPress.h"

using namespace std::filesystem;
using namespace std;

void clearConsole(); 

int main(int argc, char* argv[]) {


	setlocale(LC_ALL, "RUS");

	HWND hwnd = GetConsoleWindow();
	SetWindowText(hwnd, "Файловый менеджер");
	SetWindowPos(hwnd, HWND_TOP, 100, 200, 1000, 500, SWP_NOCOPYBITS);
	ShowWindow(hwnd, SW_SHOWNORMAL);

		cout.setf(ios::left);
		SetColor(7, 0);

		path _Path("e:/");
		_Path.preferred_separator;

		int num, i;
		while (1) {
			clearConsole();
			vector<path> vecContent(NULL);
			vecContent.push_back("...");
			
			num = 0;
			system("color 70");
			cout.setf(ios::left);
			gotoxy(5, 1);
			cout << "Полный путь: ";
			cout << setw(100) << _Path.make_preferred().generic_string() << endl;

			i = 0; 
			gotoxy(5, i + 3);
			for (auto& p : directory_iterator(_Path)) {
				vecContent.push_back(p.path());
			}
			KeyPress(vecContent, _Path);
			
			vecContent.clear();
		}

	return 0;
}

void clearConsole() {
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}