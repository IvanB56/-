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

void KeyPress(vector<path> content, path &Path);

int main(int argc, char* argv[]) {
		setlocale(LC_ALL, "RUS");
		cout.setf(ios::left);
		
		SetColor(7, 0);

		path _Path("e:/");
		_Path.preferred_separator;

		int num, i;
		while (1) {
			system("cls");
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
			cout << "1 . \"...\"" << endl;
			for (auto& p : directory_iterator(_Path)) {
				gotoxy(5, i + 4);
				cout << setw(2) << i + 2 << ". " << setw(80) << p.path().filename() << endl;
				vecContent.push_back(p.path());
				i++;
			}
			KeyPress(vecContent, _Path);
			system("cls");
			vecContent.clear();
		}

	return 0;
}