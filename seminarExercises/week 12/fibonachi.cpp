#include <iostream>
using namespace std;

int fibonachi(int num) {

	if (num == 0) {
		return 0;
	}

	if (num == 1) {
		return 1;
	}

	return fibonachi(num - 2) + fibonachi(num - 1);
}

int main() {

	int num = 0;

	cout << "Which number you wanna see in the fibonahci sequence? ";
	cin >> num;
	while (cin.fail() || num < 0) {
		cin.clear();
		cin.ignore();
		cout << "Invalid argument, try again: ";
		cin >> num;
	}

	cout << "The " << num << " in fibonachi is: " << fibonachi(num);
	return 0;
}
