#include <iostream>
using namespace std;

int counts;
void recurse (int a, int b) {
	if (a < b) {
		recurse(a, b-a);
		counts = counts*2;
	} else if (a > b) {
		recurse(a-b, b);
		counts = counts*2+1;
	} else return;
}


int main () {
	int tc, a, b, dump;
	char dump1;

	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> dump >> a >> dump1 >> b;
		if (a == b) cout << i+1 << " " << 1 << endl;
		else {
			counts = 1;
			recurse (a, b);
			cout << i+1 << " " << counts << endl;
		}
	}
	return 0;
}