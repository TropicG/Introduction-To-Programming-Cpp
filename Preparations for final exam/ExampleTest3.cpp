#include <iostream>
using namespace std;

const int SIZE_WORD = 15;
const int SIZE_ALLWORDS = 25;

//finding the size of given string
int sizeString(const char* string) {
	int size = 0;
	while (string[size] != '\0') {// adding to i until we meeat \0
		size++;
	}
	return size;
}

bool isLower(const char& ch) {
	if (ch >= 'a' && ch <= 'z') { return true; }
	return false;
}

bool isUpper(const char& ch) {
	if (ch >= 'A' && ch <= 'Z') { return true; }
	return false;
}

bool checkstr(const char* string) {

	int size = sizeString(string);
	bool order = true;
	for (int i = 0; i < size-1; i++) {
		if (isLower(string[i]) && isUpper(string[i + 1]) || (isUpper(string[i]) && isLower(string[i+1]))) {
			order = true;
		}
		else {
			order = false;
		}
	}

	return order;

}

void append(int& size, const char& symbol, char togheter[]) {
	togheter[size] = symbol;
	togheter[size + 1] = '\0';
	size++;
}

void clear(char code[], const int& size) {
	for (int i = 0; i < size; i++) {
		code[i] = '\0';
	}
}


char* getWord(char string[]) {

	char** words = new char* [SIZE_ALLWORDS];
	for (int i = 0; i < SIZE_ALLWORDS; i++) {
		words[i] = new char[SIZE_WORD];
	}
	char* word = new char[SIZE_WORD];

	int size = sizeString(string);
	for (int i = 0; i < size; i++) {
		if (string[i] == ' ') {

		}

		if()
	}

}

int main() {

	char string[20];
	cin >> string;
	if (checkstr(string)) {
		cout<<"You good dw";
	}
	else {
		cout << "You are not good";
	}

	return 0;
}
