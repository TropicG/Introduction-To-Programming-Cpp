#include <iostream>
using namespace std;

int main() {

	int mass = 0;
	char ch, previousCh;

	cout << "Enter your chemical: ";
	for (int i = 0; i < 64; ++i) {

		cin >> ch;
		while (ch != 'H' && ch != 'C' && ch != 'N' && ch != 'O' && !(ch >= '2' && ch<='9') && ch!='.') {
			cin.clear();
			cin.ignore(64, '\n');
			cout << "Invalid argument";
			cin >> ch;
		}

		if (ch == '.') {
			break;
		}

		if (ch == 'H') {
			mass += 1;
		}
		if (ch == 'C'){
			mass += 12;
		}
		if (ch == 'N') {
			mass += 14;
		}
		if (ch == 'O') {
			mass += 16;
		}

		if (ch >= '2' && ch <= '9') {

			if (previousCh == 'H') {
				mass += (ch-'0'-1) * 1;
			}
			if (previousCh == 'C') {
				mass += (ch - '0' - 1) * 12;
			}
			if (previousCh == 'N') {
				mass += (ch - '0' - 1) * 14;
			}
			if (previousCh == 'O') {
				mass += (ch - '0' - 1) * 16;
			}
		}
		previousCh = ch;
	}

	cout << "The mass of the chemical equation is: " << mass;
	return 0;
}
