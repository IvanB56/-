#include <iostream>
#include <vector>
#include <iterator>
#include <filesystem>
#include <Windows.h>
#include <iomanip>
#include <conio.h>


#include "ShowDisk.h"
#include "Color.h"

using namespace std;

void ShowDisk(vector<std::filesystem::path>& diskPath, std::filesystem::path& Path)
{

	int pos{ 1 };
	while (pos <= diskPath.size() && pos >= 1) {
		for (int i = 0; i < diskPath.size(); i++)
		{
			gotoxy(5, i + 4);
			if (i == (pos - 1)) {
				SetColor(0, 3);
				cout << i + 1 << ". " << setw(80) << diskPath[i].generic_string() << endl;
			}
			else {
				SetColor(0, 7);
				cout << i + 1 << ". " << setw(80) << diskPath[i].generic_string() << endl;
			}
		}

		int key = _getch();

		if (pos <= diskPath.size() && pos >= 1) {
			if (key == 72) {
				if (pos > 1)
					--pos;
				else if (pos < 1)
					pos = 1;
			}
			else if (key == 80) {
				if (pos <= diskPath.size())
					++pos;
				else if (pos == diskPath.size())
					pos = diskPath.size() - 1;
			}
			else if (key == 13) {
				Path = diskPath[pos - 1];
				pos = 1;
				return;
			}

			else if (key == 27)
				exit(0);
		}
	}
}