#include <iostream>
#include <stdexcept> // For std::runtime_error
using namespace std;

int main() {
    int num;
    
    cout << "Enter a number to divide 100: ";
    cin >> num;

    try {
        if (num == 0)
            throw runtime_error("Division by zero is not allowed!"); // Throw exception
        
        cout << "Result: " << (100 / num) << endl;
    } 
    catch (const runtime_error &e) {
        cout << "Error: " << e.what() << endl; // Print error message
    }

    return 0;
}