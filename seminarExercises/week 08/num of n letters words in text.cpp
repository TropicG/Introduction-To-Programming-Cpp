#include <iostream>
#include <cstring>
using namespace std;


int main() {

	int letters = 0;
	cout << "Enter lenthg of words you want to see the count: ";
	cin >> letters;
	while (cin.fail() || letters < 0) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Invalid argument, try again: ";
		cin >> letters;
	}

	char* text = new char[1024];
	cin >> text;

	int current = 0, size = strlen(text), count = 0;
	for (int i = 0; i < size; ++i) {

		if (text[i] == ' ') {
			if (current == letters) {
				count++;
			}
			current = 0;
		}
		else {
			current++;
		}
	}

	cout << "The " << letters << " letters words in the text are: " << count;
}
