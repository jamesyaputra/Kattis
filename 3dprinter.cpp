#include <iostream>
#include <math.h>
using namespace std;

int main () {
    int statues;
    int printer = 1, days = 0;
    
    cin >> statues;
    while (true) {
        if (printer >= statues) {
            days++; break;
        }
        printer += printer;
        days++;
    }
    
    cout << days << endl;
    return 0;
}