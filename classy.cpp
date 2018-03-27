#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef pair<string, string> pss;

int main () {
	int tc, n;
	string name, status, dump, token, a;
	vector <pss> m;

	cin >> tc;
	while (tc--) {
		cin >> n;
		m.clear();
		for (int i = 0; i < n; i++) {
			string hash, padding;
			cin >> name >> status >> dump;
			name.pop_back();
			
			istringstream iss(status);

			while (getline(iss, token, '-')) {
				if (token == "upper") a = "a";
				else if (token == "middle") a = "b";
				else if (token == "lower") a = "c";
				hash += a;
			}

			for (int j = 0; j < 10-(hash.length()); j++) 
				padding += "b";
			
			padding += hash;
			reverse(padding.begin(), padding.end());
			m.emplace_back(padding, name);
		}

		sort(m.begin(), m.end(), [] (const pss &a, const pss & b) {
			if (a.first != b.first) return a.first < b.first;
			return a.second < b.second;
		});

		for (auto& it : m) cout << it.second << endl;

		cout << "==============================" << endl;

	}

	return 0;
}