#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;


struct Point {
public:
	int x = 0;
	int y = 0;
};



int* getNumbers(const char* const equation) {

	int size_equation = strlen(equation);
	int* numbers = new int[3];
	int size_numbers = 0;

	for (int i = 0; i < size_equation; i++) {
		if (equation[i] == ' ') { i++; }
		if (equation[i] > '0' && equation[i] <= '9') {
			numbers[size_numbers] = equation[i]-'0';
			size_numbers++;
		}
	}

	return numbers;
}

int countDigit(int number) {
	int count = 0;
	while (number != 0) {
		number = number / 10;
		count++;
	}
	return count;

}

int* extract(const int& number) {
	int numDigits = countDigit(number);
	int* digits = new int[numDigits];
	int n = number, i = 0;
	while (n != 0) {
		digits[i] = n % 10;
		n  /= 10;
		i++;
	}
}

double Solve(const char* const equation) {

	int* numbers = getNumbers(equation);
	double a = 0, b = 0, c = 0;
	a = (double)*(numbers);
	b = (double)*(numbers + 1);
	c = (double)*(numbers + 2);

	double root1 = 0, root2 = 0;
	double diskriminanta = sqrt((pow(b, 2)) - (4*a*c));
	root1 = ((-b) + diskriminanta) / (2*a);
	root2 = ((-b) - diskriminanta) / (2*a);

	delete[] numbers;

	if (root1 > root2) { return root1; }
	else if (root2 > root1) { return root2; }
	else {
		return root1;
	}

}


bool checkRectangular(const Point& A, const Point& B, const Point& C) {

	double AB=0, BC=0, AC = 0;
	AB = sqrt(pow((B.x - A.x), 2) + pow((B.y - A.y), 2));
	BC = sqrt(pow((C.x - B.x), 2) + pow((C.y - B.y), 2));
	AC = sqrt(pow((C.x - A.x), 2) + pow((C.y - A.y), 2));

	if (pow(AC, 2) == pow(AB, 2) + pow(BC, 2)) { return true; }
	if (pow(AB, 2) == pow(AC, 2) + pow(BC, 2)) { return true; }
	if (pow(BC, 2) == pow(AB, 2) + pow(AC, 2)) { return true; }

	return false;
}

int main() {



}