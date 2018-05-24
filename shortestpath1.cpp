#include <iostream>
#include <vector>
#include <set>
#define INF 1000000000
using namespace std;

typedef pair<int, int> ii;
vector<vector<ii> > adjList;
vector<int> dist;

void dijkstra(int source) {
	set<ii> solved;
	dist[source] = 0;
	solved.insert(make_pair(0, source));

	while(!solved.empty()) {
		ii temp = *(solved.begin());
		solved.erase(temp);

		int u = temp.second;

		for (auto &it : adjList[u]) {
			int v = it.first;
			int w = it.second;

			if (dist[v] > dist[u] + w) {
				if (dist[v] != INF) solved.erase(make_pair(dist[v], v));

				dist[v] = dist[u] + w;
				solved.insert(make_pair(dist[v], v));
			}
		}
	}
}

int main () {
	int n, m, q, s;

	while (cin >> n >> m >> q >> s, n || m || q || s) {
		adjList.assign(n, vector<ii>());
		dist.assign(n, INF);
		
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			adjList[u].emplace_back(v, w);
		}

		dijkstra(s);

		while (q--) {
			int dest;
			cin >> dest;
			if (dist[dest] == INF) cout << "Impossible" << endl;
			else cout << dist[dest] << endl;
		}
	}

	return 0;
}