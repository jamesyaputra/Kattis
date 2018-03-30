#include <iostream>
using namespace std;

int main () {
	int n, x = 2;
	cin >> n;

	while (n--)
		x = x*2-1;
	cout << x*x << endl;
	return 0;
}