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
#include "KeyPress.h"
#include "ShowDisk.h"
#include "ShowCatalog.h"

using namespace std::filesystem;
using namespace std;

void clearConsole(); 

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "RUS");

	HWND hwnd = GetConsoleWindow();
	SetWindowText(hwnd, "Файловый менеджер");
	SetWindowPos(hwnd, HWND_TOP, 100, 200, 1000, 500, SWP_NOCOPYBITS);

	cout.setf(ios::left);
	system("color 70");
	//SetColor(7, 0);

	vector<std::filesystem::path> disk(NULL);
	char buf[26];
	
	GetLogicalDriveStringsA(sizeof(buf), buf);
	for (char* ptrBuf = buf; *ptrBuf; ptrBuf += strlen(buf) + 1) {
		disk.push_back((std::filesystem::path)ptrBuf);
	}

	path _Path;
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

		if (_Path.empty()) {
				ShowDisk(disk, _Path);
		}

		i = 0;
		gotoxy(5, i + 3);
		for (auto& p : directory_iterator(_Path)) {
			vecContent.push_back(p.path());
		}
			ShowCatalog(vecContent, _Path);
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