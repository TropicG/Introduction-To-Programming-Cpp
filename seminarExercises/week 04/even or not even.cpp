#include <iostream>
using namespace std;


int main() {


	int num = 0;
	cout << "Enter a num: ";
	cin >> num;

	if (num % 2 == 0) {
		cout << "The num is even";
	}
	else {
		cout << "The num is not even";
	}
	return 0;
}
