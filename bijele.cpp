#include <iostream>
using namespace std;

int main () {
	int should[6] = {1,1,2,2,2,8};

	for (int i = 0; i < 6; i++) {
		int x;
		cin >> x;
		cout << should[i]-x << " ";
	}
	cout << endl;
	return 0;
}