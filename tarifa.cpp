#include <iostream>
using namespace std;

int main () {
	int x, n, y;
	int sum = 0;

	cin >> x >> n;
	while (n--) {
		cin >> y;
		sum += (x-y);
	}
	cout << sum + x << endl;
	return 0;
}