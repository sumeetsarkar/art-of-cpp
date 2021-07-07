#include <iostream>

using namespace std;

/*
 * With knowledge of data types implement fast pow function
 * */

double _pow(double x, int y) {
    if (y == 0)
        return 1.0;
    
    if (y == 1)
        return x;

    double half = _pow(x, y/2);
    if (y % 2 == 0)
        return half * half;
    return half * half * x;
}

double pow(int x, int n) {
    if (n < 0) {
        x = 1/x;
        n = -n;
    }
    return _pow(x, n);
}


int main() {
    cout << pow(2, 3) << endl;
    cout << pow(2, 8) << endl;
}
