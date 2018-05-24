#include <iostream>
#include <vector>
#include <set>
#define INF 10000000
using namespace std;

int main () {
	int n, m, q;

	while (cin >> n >> m >> q, n || m || q) {
		int dist[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = (i == j ? 0 : INF);
			}
		}
		
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			dist[u][v] = (w < dist[u][v]?w : dist[u][v]);
		}

		//floyd-warshall
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (dist[i][j] > dist[i][k] + dist[k][j] && dist[i][k] != INF && dist[k][j] != INF)
						dist[i][j] = dist[i][k] + dist[k][j];

		//neg weight cycle detection
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; dist[i][j] != -INF && k < n; k++)
					if (dist[k][k] < 0 && dist[i][k] != INF && dist[k][j] != INF)
						dist[i][j] = -INF;

		while (q--) {
			int source, dest;
			cin >> source >> dest;
			if (dist[source][dest] == -INF) cout << "-Infinity" << endl;
			else if (dist[source][dest] == INF) cout << "Impossible" << endl;
			else cout << dist[source][dest] << endl;
		}
		cout << endl;
	}

	return 0;
}