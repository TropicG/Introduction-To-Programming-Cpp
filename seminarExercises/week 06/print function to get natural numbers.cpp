#include <iostream>
using namespace std;

void print(const int& num) {

	for (int i = 1; i <= num; ++i) {
		cout << i << " ";
	}
}

int main() {

	int num = 0;

	cout << "How many numbers do you want to print: ";
	if (!(cin >> num)) {
		cout << "Invalid argument";
		return -1;
	}

	print(num);


	return 0;
}
