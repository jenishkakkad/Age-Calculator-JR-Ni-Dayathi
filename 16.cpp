#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a number to divide 100: ";
    cin >> num;

    bool isValid = (num != 0); // Check if input is valid

    if (isValid) {
        cout << "Result: " << (100 / num) << endl;
    } else {
        cout << "Invalid input!" << endl
    }

    return 0;
}
