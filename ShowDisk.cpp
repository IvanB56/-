#include <iostream>
#include <vector>
#include <iterator>
#include <filesystem>
#include <Windows.h>
#include <iomanip>

#include "ShowDisk.h"
#include "Color.h"
#include "KeyPress.h"

using namespace std;

void ShowDisk(vector<std::filesystem::path>& diskPath, std::filesystem::path& Path)
{
	int position{ 1 };
	while (position <= (diskPath.size()) && position >= 1) {
		for (int i = 0; i < diskPath.size(); i++)
		{
			gotoxy(5, i + 4);
			if (i == position - 1) {
				SetColor(0, 3);
				cout << i + 1 << ". " << setw(80) << diskPath[i] << endl;
			}
			else {
				SetColor(0, 7);
				cout << i + 1 << ". " << setw(80) << diskPath[i] << endl;
			}
		}
		KeyPress(diskPath, Path, position);
	}
	return;
}