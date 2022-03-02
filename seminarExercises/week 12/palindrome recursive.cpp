#include <iostream>
#include <cstring>
using namespace std;

bool palindrom(const char* str, int beginning, int end) {

	if (beginning >= end) {
		return true;
	}

	if (str[beginning] != str[end]) {
		return false;
	}

	return palindrom(str, beginning + 1, end - 1);

}

int main() {

	char str[64];

	cout << "Enter the string: ";
	cin >> str;

	if (palindrom(str, 0, strlen(str) - 1)) {
		cout << "Palindrome";
	}
	else {
		cout << "Not palindrome";
	}

	return 0;
}
