#include <bits/stdc++.h>
using namespace std;

int main () {
	int cases;
	string name, in;
	map<string, vector<string> > menu;
	vector<string> input;
	while (1) {
		cin >> cases;
		if (!cases) break;
		menu.clear();
		while(cases--) {
			input.clear();
			cin >> name;
			do {
				cin >> in;
				input.push_back(in);
			} while (cin.get() != '\n');

			for (auto it = input.begin(); it != input.end(); it++) {
				menu[*it].push_back(name);
			}
		}

		for (auto it = menu.begin(); it != menu.end(); it++) 
			stable_sort(it->second.begin(), it->second.end());

		for (auto& it : menu) {
			cout << it.first << " ";
			for (auto itt = it.second.begin(); itt != it.second.end(); itt++)
				cout << *itt << " ";
			cout << endl << endl;
		}
	}
	return 0;
}