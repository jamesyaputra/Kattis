#include <iostream>
#include <math.h>
#include <set>
using namespace std;

int main () {
    unsigned long long i;
    set<unsigned long long> s;
    
    cin >> i;
    for (unsigned long long j = 1; j <= (double)(pow(i, 0.5)); j++) {
        if (!(i%j)) {
            s.insert(j-1);
            s.insert((i/j)-1);
        }
    }
    
    for (auto& it : s) cout << it << " ";
    cout << endl;
    return 0;
}