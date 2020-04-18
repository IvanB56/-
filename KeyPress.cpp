#ifdef SHOW_DISK
#include <iostream>
#include <filesystem>
#include <vector>
#include <conio.h>
#include <Windows.h>

#include "Color.h"

using namespace std;
#include "KeyPress.h"
void KeyPress(vector<std::filesystem::path> content,
	std::filesystem::path &Path, int &pos)
{
	int key = _getch();

		if (pos <= content.size() && pos >= 1) {
			if (key == 72) {
				if (pos > 1)
					--pos;
				else if (pos < 1) 
					pos = 1;
			}
			else if (key == 80) {
				if (pos <= content.size())
					++pos;
				else if (pos == content.size()) 
					pos = content.size() - 1;
			}
			else if (key == 13) {
				Path.assign(content[pos - 1]);
				pos = 1;
				return;
			}

			else if (key == 27) 
				exit(0);
		}
}
#endif //SHOW_DISK
#ifdef SHOW_CATALOG
#include <iostream>
#include <filesystem>
#include <vector>
#include <conio.h>
#include <Windows.h>

#include "Color.h"

using namespace std;
#include "KeyPress.h"

void KeyPress(vector<std::filesystem::path> content,
		      std::filesystem::path & Path, int& pos)
{
	int key = _getch();

	if (pos <= content.size() && pos >= 1) {
		if (key == 72) {
			if (pos > 1)
				--pos;
			else if (pos < 1) pos = 1;
		}
		else if (key == 80) {
			if (pos <= content.size())
				++pos;
			else if (pos > (content.size() - 1)) pos = content.size() - 1;
		}
		else if (key == 13) {
			if (position == 1) {
				Path = Path.parent_path();
				return;
			}
			else {
				Path = content[pos - 1];
				return;
			}
		}
		else if (key == 27) exit(0);
	}
}
#endif //SHOW_CATALOG
