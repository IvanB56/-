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
#include "ShowDisk.h"
#include "ShowCatalog.h"

using namespace std::filesystem;
using namespace std;

void clearConsole(); 


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "RUS");

	unsigned short begin{ 0 }, end{ 0 };

	HWND hwnd = GetConsoleWindow();
	SetWindowText(hwnd, "Файловый менеджер");
	SetWindowPos(hwnd, HWND_TOP, 100, 200, 1000, 500, SWP_NOCOPYBITS | SWP_NOREPOSITION | SWP_NOMOVE);

	/*HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int w = 90, h = 30;
	SMALL_RECT zeroWindow = { 0, 0, 0, 0 };
	COORD zBuffer = { 1, 1 };
	SetConsoleWindowInfo(hStdOut, TRUE, &zeroWindow);
	SetConsoleScreenBufferSize(hStdOut, zBuffer);

	COORD bufferSize = { w, h };
	SMALL_RECT windowSize = { 0, 0, w - 1, h - 1 };
	SetConsoleScreenBufferSize(hStdOut, bufferSize);
	SetConsoleWindowInfo(hStdOut, TRUE, &windowSize);*/

	cout.setf(ios::left);
	system("color 70");

	vector<std::filesystem::path> disk(NULL);
	char buf[26];
	
	GetLogicalDriveStringsA(sizeof(buf), buf);
	for (char* ptrBuf = buf; *ptrBuf; ptrBuf += strlen(buf) + 1) {
		disk.push_back((std::filesystem::path)ptrBuf);
	}

	path _Path;

	int num, i;
	while (1) {
		clearConsole();
		vector<path> vecContent(NULL);

		num = 0;
		system("color 70");
		cout.setf(ios::left);
		gotoxy(5, 1);
		cout << "Полный путь: ";
		cout << setw(100) << _Path.generic_string() << endl;

		if (_Path.empty()) {
			ShowDisk(disk, _Path);
		}

		i = 0;
		gotoxy(5, i + 3);
		for (auto& p : directory_iterator(_Path)) {
			vecContent.push_back(p.path());
		}

		if (vecContent.size() < 23)
			end = vecContent.size();
		else if (end < 24)
			end = 23;

		ShowCatalog(vecContent, _Path, begin, end);

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