#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
vector<vi> sites;
vi visited;
vi label;

void visit(int source, int pub) {
	visited[source] = 1;
	label[source] = pub;
	for (int &it : sites[source]) if (!visited[it]) visit(it, (pub+1)%2);
}

int main () {
	int n, m;

	cin >> n >> m;
	sites.assign(n, vi());
	visited.assign(n, 0);
	label.assign(n, 0);
	while (m--) {
		int a, b;
		cin >> a >> b;
		sites[a-1].push_back(b-1);
		sites[b-1].push_back(a-1);
	}

	for (int i = 0; i < n; i++) {
		if (sites[i].empty()) {
			cout << "Impossible\n";
			return 0;
		} else if (!visited[i]) {
			visit(i, 0);
		}
	}

	for (auto &it : label) {
		if (!it) cout << "pub ";
		else cout << "house ";
	}
 	cout << endl;
	return 0;
}