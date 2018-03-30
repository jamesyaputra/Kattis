#include <iostream>
using namespace std;

int main () {
	string in;
	cin >> in;

	if (in.find("ss") < in.size()) cout << "hiss";
	else cout << "no hiss";
	cout << endl;
	return 0;
}