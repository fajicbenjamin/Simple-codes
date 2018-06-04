//
//  Bi-Dec Converter
//
//  Created by Benjamin Fajic on 04/10/2016.
//  Copyright © 2016 Benjamin Fajic. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int power(int theNumber, int exponent);
int convertToDecimal(int number);
int convertToBinary(int number);
string stringToBinary(int number);

int main() {
    int number;
    char input;
    cout << "Hello! Press B to convert from binary to decimal or D from decimal to binary! ";
    cin >> input;
    if (tolower(input, locale()) == 'd') {
        cout << "\nEnter decimal number to be converted to binary: ";
        cin >> number;
        cout << "Number is: " << stringToBinary(number) << endl;
    } else if (tolower(input, locale()) == 'b') {
        cout << "\nEnter binary number to be converted to decimal: ";
        cin >> number;
        cout << "Number is: " << convertToDecimal(number) << endl;
    } else {
        cout << "\nSorry, you didn't press B or D key." << endl;
    }
    return 0;
}

int power(int theNumber, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= theNumber;
    }
    return result;
}

int convertToDecimal(int number) {
    int result = 0, c = 0;
    while (number > 0) {
        result += number % 10 * power(2, c++);
        number /= 10;
    }
    return result;
}

int convertToBinary(int number) {
    /* Because of using int, function just converts up to number 1023(decimal) */
    int result = 0, c = 0;
    while (number > 0) {
        result += number % 2 * power(10, c++);
        number /= 2;
    }
    return result;
}

string stringToBinary(int number) {
    string result;
    while (number > 0) {
        result = (number % 2 == 0 ? "0" : "1") + result;
        number /= 2;
    }
    return result;
}
