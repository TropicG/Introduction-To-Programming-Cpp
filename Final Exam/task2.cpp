#include <iostream>
#include <cstring>
using namespace std;

int strToNum(const char* str) {

	int size = strlen(str), num = 0;

	for (int i = 0; i < size; ++i) {
		num *= 10;
		num += str[i] - '0';
	}
	return num;
}

void clear(char* str) {

	int size = strlen(str);

	for (int i = 0; i < size; ++i) {
		str[i] = '\0';
	}

}

int main() {

	char equation[1024 + 1];
	cout << "Enter your equation: ";
	cin >> equation;

	char numbers[][6] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	char symbols[][6] = { "minus","plus" };


	char converted[256 + 1];
	int convertedIndex = 0;

	int size = strlen(equation);
	int i = 0;
	for (i; i < size - 5;) {

		char helper[6];
		int helperIndex = 0;

		helper[helperIndex] = equation[i];
		helperIndex++;

		helper[helperIndex] = equation[i + 1];
		helperIndex++;

		helper[helperIndex] = equation[i + 2];
		helperIndex;

		helper[helperIndex] = '\0';

		if (strcmp(helper, "one") == 0) {
			converted[convertedIndex] = '1';
			convertedIndex++;

			i += 3;
		}
		else if (strcmp(helper, "two")==0) {
			converted[convertedIndex] = '2';
			convertedIndex++;

			i += 3;
		}
		else if (strcmp(helper, "six") == 0) {
			converted[convertedIndex] = '6';
			convertedIndex++;

			i += 3;
		}
		else {

			helper[helperIndex] = equation[i + 3];
			helperIndex++;

			helper[helperIndex] = '\0';

			if (strcmp(helper, "zero") == 0) {
				converted[convertedIndex] = '0';
				convertedIndex++;

				i += 4;
			}
			else if (strcmp(helper, "four") == 0) {
				converted[convertedIndex] = '4';
				convertedIndex++;

				i += 4;
			}
			else if (strcmp(helper, "five") == 0) {
				converted[convertedIndex] = '5';
				convertedIndex++;

				i += 4;
			}
			else if (strcmp(helper, "nine") == 0) {
				converted[convertedIndex] = '9';
				convertedIndex++;

				i += 4;
			}
			else if (strcmp(helper, "plus") == 0) {
				converted[convertedIndex] = '+';
				convertedIndex++;

				i += 4;
			}
			else {

				helper[helperIndex] = equation[i + 4];
				helperIndex++;

				helper[helperIndex] = '\0';

				if (strcmp(helper, "three") == 0) {
					converted[convertedIndex] = '3';
					convertedIndex++;

					i += 5;
				}
				else if (strcmp(helper, "seven") == 0) {
					converted[convertedIndex] = '7';
					convertedIndex++;

					i += 5;
				}
				else if (strcmp(helper, "eight") == 0) {
					converted[convertedIndex] = '8';
					convertedIndex++;

					i += 5;
				}
				else {
					converted[convertedIndex] = '-';
					convertedIndex++;

					i += 5;
				}
			}
		}
	}

	converted[convertedIndex] = '\0';

	char symb = '/0';
	int endResult = 0, sizeConverted = strlen(converted);

	char helperConverted[16];
	int helperConvertedIndex = 0;

	for (int i = 0; i < sizeConverted; ++i) {

		if (converted[i] >= '0' || converted[i] <= '9') {
			helperConverted[helperConvertedIndex] = converted[i];
			helperConvertedIndex++;
		}

		if (converted[i] == '+') {

			if (symb == '\0') {
				endResult = strToNum(helperConverted);
				clear(helperConverted);
			}
			else {
				endResult += strToNum(helperConverted);
				clear(helperConverted);
			}

		}

		if (converted[i] == '-') {

			if (symb == '\0') {
				endResult = strToNum(helperConverted);
				clear(helperConverted);
			}
			else {
				endResult -= strToNum(helperConverted);
				clear(helperConverted);
			}
		}

	}

	cout << "The final result is: " << endResult;

	return 0;
}
