#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
vector<vi> terraces;
vector<vi> visited;
int counts = 0;
int sizes = 0;
bool flow = true;

void dfs(int i, int j, int n, int m, int height) {
	if (i < 0 || j < 0 || i == n || j == m) return;
	if (visited[i][j]) return;
	visited[i][j] = 1;
}

int main () {
	int n, m;
	
	cin >> n >> m;
	terraces.assign(n, vi(m, 0));
	visited.assign(n, vi(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> terraces[i][j];
		}
	}

	//dfs(0, 0, n, m, -1);
	cout << counts << endl;
	return 0;
}