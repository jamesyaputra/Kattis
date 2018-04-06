#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
vector<vector<char> > adj;
vector<vi> visited;
int counts = 0;

void dfs(int i, int j, int n, int m) {
	if (i < 0 || j < 0 || i == n || j == m) return;
	if (visited[i][j]) return;
	
	if (adj[i][j] == '1') counts++;
	else {
		visited[i][j] = 1;
		dfs(i+1, j, n, m);
		dfs(i-1, j, n, m);
		dfs(i, j+1, n, m);
		dfs(i, j-1, n, m);
	}
}

int main () {
	int n, m;

	cin >> n >> m;
	adj.assign(n+2, vector<char>(m+2, '0'));
	visited.assign(n+2, vi(m+2, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char a;
			cin >> a;
			adj[i][j] = a;
		}
	}

	dfs(0,0,n+2, m+2);
	cout << counts << endl;
	return 0;
}