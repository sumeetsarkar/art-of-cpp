#include <iostream>

using namespace std;

int main() {
    int x = 10;

    cout << "value of x: " << x << endl;
    x = 11;
    cout << "value of x: " << x << endl;

    const int y = 100;
    cout << "value of y: " << y << endl;

    //y = 101; constants cannot be modified
    
    // Following is not allowed either
    // have to initialize a constant at the time of its declaration
    //const int z;
    //z = 100;
}
