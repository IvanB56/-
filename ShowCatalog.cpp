#include <iostream>
#include <vector>
#include <iterator>
#include <filesystem>
#include <Windows.h>
#include <iomanip>
#include <conio.h>

#include "ShowCatalog.h"
#include "Color.h"
#include "Navigation.h"
#include "OperationWithCatalog.h"

//����� �� ����� ������ ���������/������ � ������ � ����
void ShowCatalog(std::vector<std::filesystem::path> &content, std::filesystem::path &Path, 
				unsigned short &beg, unsigned short &end) 
{
	int position = beg + 1;
	if (end == 0) {
		char key = _getch();
		if (key == 224) {
			key = _getch();
		}
		if (key == 8) {
			Path = Path.parent_path();
			return;
		}
		if (key == 61) {
			CreatNewCatalog(Path);
			return;
		}
		if (key == 62) {
			CreatNewFile(Path);
			return;
		}
	}
	while (position <= end && position >= beg + 1) {
		Navigation(content, beg, end, position);
		char key = _getch();
		if (key == 224) {
			key = _getch();
		}
		if (position <= content.size() && position >= 1) {
			if (key == 72) {
				if (position > 0)
					--position;
				else if (position < 1) position = 1;
			}
			else if (key == 80) {
				if (position <= content.size())
					++position;
				else if (position > content.size()) position = (content.size() - 1);
			}
			else if (key == 13) {
				Path = content[position - 1];
				beg = 0;
				return;
			}
			else if (key == 8) {
				Path = Path.parent_path();
				return;
			}
			else if (key == 71) {
				Path.clear();
				return;
			}
			else if (key == 81) {
				if (content.size() >= 23) {
					if (end != content.size()) {
						beg = end;
						end += 23;
					}
					if (end >= content.size()) {
						end = content.size();
						return;
					}
				}
				return;
			}
			else if (key == 73) {
				if (content.size() >= 23 && beg >= 0) {
					if (beg != 0) {
						end = beg;
						beg -= 23;
					}
					else if (beg < 0) {
						beg = 0;
					}
				}
				return;
			} else if (key == 61){
				CreatNewCatalog(Path);
				return;
			} else if (key == 83) {
				deleteCatalog(content[position - 1]);
				return;
			} else if (key == 62) {
				CreatNewFile(Path);
				return;
			} else if (key == 27) exit(0);
		}
	}	
}