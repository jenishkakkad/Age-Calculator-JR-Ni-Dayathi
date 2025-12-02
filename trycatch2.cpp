#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    int age;
    cout << "Enter your age: ";
    cin >> age;

    try {
        if (age < 0)
            throw invalid_argument("Age cannot be negative!"); // Throw exception
        cout << "Your age is: " << age << " years." << endl;
    } 
    catch (const invalid_argument &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}