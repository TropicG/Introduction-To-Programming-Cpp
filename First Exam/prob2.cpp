#include <iostream>
using namespace std;

bool susedi(int num, int previous) {

	if ((num < 10) && num != previous) {
		return true;
	}


	int next = (num / 10) % 10;
	int current = num % 10;

	if (current == next || current == previous) {
		return false;
	}

	return susedi(num / 10, num % 10);

}

int sub(int a, int b, int min, int max) {

	if (a > b && (!susedi(max, -1) || !susedi(min, -1))) {
		return -100;
	}
	if (a > b) {
		return max - min;
	}
	else if (susedi(a,-1) && a < min) {
		return sub(a+1, b, a, max);
	}
	else if (susedi(a, -1) && a > max) {
		return sub(a+1, b, min, a);
	}
	else {
		return sub(a+1, b, min, max);
	}

}

int getfirst(int a, int b) {
	if (a > b) {
		return -100;
	}
	else if (susedi(a, -1)) {
		return a;
	}
	else {
		getfirst(a + 1, b);
	}
}

int main() {

	int a = 0, b = 0;

	if (!(cin >> a) || !(cin >> b)) {
		cout << "Invalid argument";
		return -1;
	}
	else if (a < 0 || b < 0) {
		cout << "The arguments should not be less than 0";
		return -2;
	}
	else if (a > b) {
		cout << "A should not be higher than b";
		return -3;
	}
	int min = getfirst(a, b);
	if (min == -100) {
		cout << "No adjacend numbers";
		return -5;
	}
	int num = sub(a, b, min, a);

	if (num == -100) {
		cout << "No adjacend numbers";
		return -4;
	}
	else {
		cout << num;
	}


}
