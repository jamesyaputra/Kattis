#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
bool possible = true;
vector<vi> adj;
vi visited, output;

void toposort(int source) {
	visited[source] = 1;
	for (auto &it : adj[source]) {
		if (!visited[it]) toposort(it);
		else if (visited[it] == 1) {
			possible = false;
			return;
		}
	}
	output.push_back(source);
	visited[source] = 2;
}

int main () {
	int n, m;

	cin >> n >> m;
	adj.assign(n, vi());
	visited.assign(n, 0);
	while(m--) {
		int a, b;
		cin >> a >> b;
		adj[a-1].push_back(b-1);
	}

	for (int i = 0; i < n; i++)
		if (!visited[i]) toposort(i);

	if (possible) for (int i = output.size()-1; i >= 0; i--) cout << output[i]+1 << endl;
	else cout << "IMPOSSIBLE\n";


	return 0;
}