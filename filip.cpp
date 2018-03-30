#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main () {
	string a, b;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int c, d;
	c = stoi(a);
	d = stoi(b);

	if (c > d) cout << c;
	else if (c < d) cout << d;
	cout << endl;
	return 0;
}