#include <iostream>
#include <cstring>
using namespace std;

//makes all uppercase characters to be lowercase
void allLower(char str[]) {

	//gets teh size of the string
	int size = strlen(str);

	for (int i = 0; i < size; ++i) {

		//if a character is between A-Z it will be changed to respectivly a-z
		if (str[i] >= 'A' && str[i] < 'Z') {
			str[i] += 40;
		}
	}
}

unsigned longestSequence(char* s) {

	//max remembers the longest substr, while current remembers the substr until a different character is met
	unsigned max = 0, current = 1;

	//gets the size of the string
	int size = strlen(s);

	//cycle all the string
	for (int i = 0; i < size - 1; ++i) {

		//if the next symbol is equal to the current we increment current variable
		if (s[i] == s[i + 1]) {
			current++;
		}

		//if the next symbol is not equal to the current we check is the current bigger then max
		//if it is then max becomes current and we reset current to 1
		if (s[i] != s[i + 1]) {
			if (current > max) {
				max = current;
			}
			current = 1;
		}
	}

	//return the max substring at the end
	return max;
}

int main() {

	char str[256];
	cout << "Enter your string: ";
	cin >> str;

	//makes all the character lowercase so that uppercase characters can be counted
	allLower(str);

	cout << "The longes substring is: " << longestSequence(str);
	return 0;
}
