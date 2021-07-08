#include <iostream>

using namespace std;

int main() {
    /*
     * Primitive types
     * 1. integer
     * 2. float
     * 3. double
     * 4. char
     * 5. boolean
     * 6. void
     * */

    // int - strictly integer storing 4 bytes of memory
    // and range -2^31 to 2^31-1
    int number = 2;
    cout << "number value is: " << number << endl;

    // int truncation
    int integer_num = 2.5;
    cout << "integer number value is: " << integer_num << endl;

    // floating point data type storing 4 bytes of memory
    // and range -2^31 to 2^31-1
    float floating_point_num = 2.5;
    cout << "floating point number value is: " << floating_point_num << endl;

    // double data type storing 8 bytes of memory
    // and range -2^63 to 2^63-1
    double double_number = 2.56789;
    cout << "double number value is: " << double_number << endl;
    // NOTE: default value of double is garbage
    
    // double provides more precision after decimal
    // float precision upto 7 digits after decimal
    // double precision upto 15 digits after decimal

    // storing scientific numbers
    double speed_of_light_ms = 3e8;
    double planck_constant = 6.26e-34;

    cout << "speed of light (m/s): " << speed_of_light_ms << endl;
    cout << "plancks constant: " << planck_constant << endl;

    // char data type stores 1 byte of memory
    // range -2^7 to 2^7-1
    // It denotes a single character from ASCII and is only
    // within single quotes

    char mycharacter = 'S';
    cout << "mycharacter value is: " << mycharacter << endl;

    // bool data type stores 1 byte of memory
    // but restricted to store only true or false which
    // can also be denoted using 1 or 0

    bool is_learning = true;
    cout << "is_learning value is: " << is_learning << endl;
}
