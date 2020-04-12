#include <iostream>
#include <filesystem>
#include <vector>
#include <conio.h>
#include <Windows.h>

#include "Color.h"

using namespace std::filesystem;
using namespace std;

void KeyPress(std::vector<std::filesystem::path> content, std::filesystem::path &Path) {
	int position{ 1 };
	while (position != (content.size() + 1) && position >= 1) {
		int key = _getch();
		for (int i = 0; i < content.size(); i++) {
			if (i == position) {
				SetColor(0, 3);
				cout << content[i] << endl;
			}
			else {
				SetColor(0, 7);
				cout << content[i] << endl;
			}
		}
		if (position <= content.size() && position >= 1) {
			if (key == 72) {
				if (position > 1)
					cout << --position;
				else if (position < 1) position = 1;
			}
			else if (key == 80) {
				if (position <= content.size())
					cout << ++position;
				else if (position == content.size()) position = content.size() - 1;
			}
			else if (key == 13) {
				if (position == 1) {
					Path = Path.parent_path();
					return;
				}
				else {
					Path = content[position - 1].filename();
					return;
				}
			}
			else if (key == 27) exit(0);
		}
	}
}