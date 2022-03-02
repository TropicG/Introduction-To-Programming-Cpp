#include <iostream>
using namespace std;


int main() {


	int num = 0;
	cout << "Enter a num: ";
	if (!(cin >> num) || num < 0) {
		cout << "Invalid argument";
		return -1;
	}

	cout << "All the squared number below the number you entered are: ";
	for (int i = 1; i < num; ++i) {

		if (i*i >= num) {
			break;
		}

		cout << (i*i) << " ";

	}

	return 0;
}
