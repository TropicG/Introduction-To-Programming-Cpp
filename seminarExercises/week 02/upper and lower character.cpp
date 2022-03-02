#include <iostream>
using namespace std;


int main() {

	char c;
	cout << "Enter your character: ";
	cin >> c;

	if (!(c >= 'A' && c <= 'Z')) {
		cout << "Your input was invalid";
		return -1;
	}

	cout << "The lower character of your letter is: " << (char)(c + 32);
	return 0;
