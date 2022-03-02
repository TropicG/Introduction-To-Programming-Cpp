#include <iostream>
using namespace std;

int main()
{
    int num =0;
    cout << "Enter the size of the snowflake: ";
    if (!(cin >> num) || num<=3) {
        cout << "Invalid argument";
    }

    for (int i = 0; i < num; i++){
        for (int j = 0; j < num; j++){

            if (i == j || i + j == num - 1 || i == num / 2 || j == num / 2)
                cout << '*';
            else
                cout << '.';
        }
        cout << '\n';
    }

    return 0;
}
