#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <set>
using namespace std;

typedef set<string> vs;
unordered_map<string, vs> subway;
set<string> visited;
vector<string> route;
bool found = false;

void dfs(string source, string dest) {
	visited.insert(source);
	if (source == dest) found = true;
	for (auto &it : subway[source]) {
		if (found) break;
		if (visited.find(it) == visited.end()) dfs(it, dest);
	}
	if (found) route.push_back(source);
}

int main () {
	int n;
	string s;

	cin >> n;
	getline(cin, s);
	while (n--) {
		vector<string> fragment;
		string in;

		getline(cin, s);
		istringstream iss(s);
		while (iss >> in) fragment.push_back(in);

		for (int i = 1; i < fragment.size(); i++) {
			subway[fragment[0]].insert(fragment[i]);
			subway[fragment[i]].insert(fragment[0]);
		}
	}

	string a, b;
	cin >> a >> b;
	dfs(a, b);

	if (found) for (int i = (int)route.size()-1; i >= 0; i--) cout << route[i] << " ";
	else cout << "no route found";
	cout << endl;

	return 0;
}