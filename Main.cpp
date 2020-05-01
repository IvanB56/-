#include <iostream>
#include <windows.h>
#include <conio.h>
#include <locale>
#include <string>
#include <iomanip>
#include <vector>
#include <iterator>
#include <filesystem>

#include "Color.h"
#include "ShowDisk.h"
#include "ShowCatalog.h"
#include "CllearConsol.h"


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "RUS");
	unsigned short begin{ 0 }, end{ 0 };
	HWND hwnd = GetConsoleWindow();
	std::filesystem::path _Path;
	std::vector<std::filesystem::path> disk(NULL);
	int num, i;

	SetWindowText(hwnd, "Файловый менеджер");
	SetWindowPos(hwnd, HWND_TOP, 100, 200, 800, 550, SWP_NOCOPYBITS | SWP_NOREPOSITION | SWP_NOMOVE);
	std::cout.setf(std::ios::left);
	system("color 70");

	char buf[26];
	GetLogicalDriveStringsA(sizeof(buf), buf);
	for (char *ptrBuf = buf; *ptrBuf; ptrBuf += strlen(buf) + 1) {
		int d = GetDriveTypeA(ptrBuf);
		if (d == DRIVE_FIXED) {
			disk.push_back((std::filesystem::path)ptrBuf);
		}
	}
	
	while (1) {
		clearConsole();
		std::vector<std::filesystem::path> vecContent(NULL);
		num = 0;
		system("color 70");
		std::cout.setf(std::ios::left);
		gotoxy(5, 1);
		std::cout << "Полный путь: ";
		std::cout << std::setw(100) << _Path.generic_string() << std::endl;
		if (_Path.empty()) {
			ShowDisk(disk, _Path);
		}
		i = 0;
		gotoxy(5, i + 3);
		for (auto& p : std::filesystem::directory_iterator(_Path)) {
			vecContent.push_back(p.path());
		}
		if (vecContent.size() < 23) {
			end = vecContent.size();
		} else if (end < 24){
			end = 23;
		}
		ShowCatalog(vecContent, _Path, begin, end);
		vecContent.clear();
	}
	return 0;
}

