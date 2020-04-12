#include <iostream>
#include <filesystem>
#include <vector>
#include <conio.h>
#include <Windows.h>

#include "Color.h"

using namespace std;

void KeyPress(std::vector<std::filesystem::path> content, std::filesystem::path &Path) {
	int position{ 1 };
	
	while (position <= (content.size()) && position >= 1) {
		for (int i = 0; i < content.size(); i++)
		{
			gotoxy(5, i + 4);
			if (i == position - 1) {
				SetColor(0, 3);
				cout << setw(2) << i + 1 << ". " << setw(80) << content[i].filename() << endl;
			}
			else {
				SetColor(0, 7);
				cout << setw(2) << i + 1 << ". " << setw(80) << content[i].filename() << endl;
			}
		}
		int key = _getch();

		if (position <= content.size() && position >= 1) {
			if (key == 72) {
				if (position > 1)
					--position;
				else if (position < 1) position = 1;
			}
			else if (key == 80) {
				if (position <= content.size())
					++position;
				else if (position > (content.size() - 1)) position = content.size() - 1;
			}
			else if (key == 13) {
				if (position == 1) {
					Path = Path.parent_path();
					return;
				}
				else {
					Path = content[position - 1];
					return;
				}
			}
			else if (key == 27) exit(0);
		}
	}
}