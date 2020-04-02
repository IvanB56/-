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

using namespace std::filesystem;
using namespace std;

int main(int argc, char* argv[]) {
		setlocale(LC_ALL, "RUS");
		//system("mode con cols=100 lines=80");
		//system("color 70");
		cout.setf(ios::left);
		
		//path pathHard = HardDisk();
		//cout << pathHard;
		SetColor(7, 0);
		/*HWND window_header = GetConsoleWindow();
		SetWindowPos(window_header, HWND_TOPMOST, 100, 50, 1000, 800, NULL);
		*/

		path _Path("e:/");
		_Path.preferred_separator;

		int num, i;
		while (1) {
			system("cls");
			vector<path> vecContent(NULL);
			
			num = 0;
			system("color 70");
			cout.setf(ios::left);
			gotoxy(5, 1);
			cout << "Ïîëíûé ïóòü: ";
			SetColor(15, 1);
			cout << setw(100) << _Path.make_preferred().generic_string() << endl;

			i = 0;
			for (auto& p : directory_iterator(_Path)) {
				gotoxy(5, i + 4);
				std::cout << setw(2) << i + 1 << ". " << setw(80) << p.path().filename() << '\n';
				vecContent.push_back(p.path());
				i++;
			}
			cin >> num;
			if (num > 0) {
				_Path = vecContent[num - 1];
			}
			else {
				_Path = _Path.parent_path();
			}
			vecContent.clear();
		}
		
	return 0;
}
