#include <iostream>
#include <cstring>
using namespace std;

bool valid(const char* str) {

	int size = strlen(str);

	for (int i = 0; i < size; ++i) {
		if (str[i] != 'r' && str[i]!='g' && str[i] != 'y') {
			return false;
		}
	}

	return true;
}

int main() {


	char str[1024 + 1];

	cout << "Enter the string: ";
	cin >> str;
	while (!valid(str)) {
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "You have used different symbol than r,y,g, try again: ";
		cin >> str;
	}


	int maxRoute = 0, currentRoute = 0, size = strlen(str);
	bool yellow = false;

	for (int i = 0; i < size; ++i) {
		for (int j = i; j < size; ++j) {

			if(str[j] == 'r' && yellow==false){
				if (currentRoute > maxRoute) {
					maxRoute = currentRoute;
				}
				currentRoute = 0;
				break;
			}
			else if(str[j] == 'r' && yellow == true && j!=size-1) {
				currentRoute += 0;
			}
			else if (str[j] == 'g' && yellow == false) {
				currentRoute++;
			}
			else if(str[j] == 'g' && yellow == true) {
				currentRoute++;
				yellow = false;
			}
			else if (str[j] == 'y' &&  yellow == false) {
				currentRoute++;
				yellow = true;
			}
			else if (str[j] == 'y' && yellow == true) {
				currentRoute += 0;
			}
			else {
				if (currentRoute - 1 > maxRoute) {
					maxRoute = currentRoute - 1;
				}
				yellow = false;
				currentRoute = 0;
				break;
			}
		}
	}

	cout << "The maximum number is turns is: " << maxRoute;
	return 0;
}
