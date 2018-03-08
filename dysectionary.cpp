#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main () {
	vector<string> names;
	string name, compare;
	int max = -1;
	while (getline(cin, name)) {
		names.push_back(name);
		if (name.length() > max){
			max = (int)name.length();
			compare = name;
		}

		if (name.empty()) {
			sort(names.begin(), names.end(), [] (string a, string b) {
				reverse(a.begin(), a.end());
				reverse(b.begin(), b.end());
				return a < b;
			});

			for (auto it = names.begin(); it != names.end(); it++) {
				cout << *it << endl;
			}
			names.clear();
			cout << endl;
		}
	}
	return 0;
}