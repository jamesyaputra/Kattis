#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > internet;
vector<int> visited;

void dfs(int source) {
	visited[source] = 1;
	for (auto &it : internet[source])
		if (!visited[it]) dfs(it);
}

int main () {
	int a, b;

	cin >> a >> b;
	internet.assign(a, vector<int>());
	for (int i = 0; i < b; i++) {
		int c, d;
		cin >> c >> d;
		internet[c-1].push_back(d-1);
		internet[d-1].push_back(c-1);
	}

	visited.assign(a, 0);
	dfs(0);
	int flag = 0;
	for (int i = 0; i < a; i++) {
		if (!visited[i]) {
			flag = 1;
			cout << i + 1 << endl;
		}
	}

	if (!flag) cout << "Connected" << endl;
	return 0;
}