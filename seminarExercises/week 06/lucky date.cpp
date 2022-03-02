#include <iostream>
using namespace std;

bool valid(const int& day, const int& month, const int& year) {

	if (month == 4 || month == 6 || month == 9 || month == 11 && day == 31) {
		return false;
	}

	if (month == 2 && day > 29) {
		return false;
	}

	bool leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
	if(!leap && month == 2 && day > 28){
		return false;
	}

	return true;
}

int sumDigits(int day) {

	if (day < 10) {
		return day;
	}

	return day % 10 + sumDigits(day / 10);
}

bool lucky(const int& day, const int& month, const int& year) {

	if ((sumDigits(day) + sumDigits(month) + sumDigits(year)) % 6 == 0) {
		return true;
	}

	return false;
}

int main() {

	int day = 0, month = 0, year = 0;
	char ch;

	cout << "Enter your date: ";
	if (!(cin >> day) || day <= 0 || day > 31) {
		cout << "Invalid argument";
		return -1;
	}
	cin >> ch;
	if (!(cin >> month) || month <= 0 || month > 12) {
		cout << "Invalid argument";
		return -2;
	}
	cin >> ch;
	if (!(cin >> year) || year < 0) {
		cout << "Invalid argument";
		return -3;
	}

	if (!valid(day, month, year)) {
		cout << "Invalid time!";
		return -4;
	}

	if (lucky(day, month, year)) {
		cout << "Lucky";
		return 1;
	}
	else {
		cout << "Not Lucky";
		return 2;
	}
}
