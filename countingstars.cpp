#include <iostream>
#include <vector>
using namespace std;

vector<vector<char> > sky;
vector<vector<int> > visited;

void fill (int m, int n, int i, int j) {
	if (i == m || j == n || i < 0 || j < 0) return;
	if (sky[i][j] == '#' || visited[i][j]) return;
	if (sky[i][j] == '-') visited[i][j] = 1;
	fill(m, n, i+1, j);
	fill(m, n, i-1, j);
	fill(m, n, i, j+1);
	fill(m, n, i, j-1);
}

int main() {
	int m, n, counts, cases = 1;
	char in;

	while (cin >> m >> n) {
		counts = 0;
		sky.assign(m, vector<char>());
		visited.assign(m, vector<int>());

		for (auto &it : visited) it.assign(n, 0);
		
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> in;
				sky[i].push_back(in);
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j] && sky[i][j] == '-') {
					fill(m,n,i,j);
					counts++;
				}
			}
		}

		cout << "Case " << cases++ << ": " << counts << endl;
	} 

	return 0;
}