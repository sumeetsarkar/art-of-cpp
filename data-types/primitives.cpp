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
}
