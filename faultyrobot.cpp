#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef pair<int, int> ii;
vector<set<int> > adj;
vector<int> visited;
set<ii> forced;
int counts = 0;

void runRobot(int v, int fault) {
	if (!visited[v]) {
		bool flag = 0;
		visited[v] = 1;
		for (auto &it : adj[v]) {
			if (forced.find(ii(v, it)) != forced.end()) {
				flag = 1;
				runRobot(it, fault);
			}
		}

		if (!flag) counts++;
		if (!fault) for (auto &it : adj[v]) runRobot(it, 1);
	}
}

int main () {
	int v, e;
	cin >> v >> e;
	visited.assign(v, 0);
	adj.assign(v, set<int>());

	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		if (a < 0) {
			adj[-(a+1)].insert(b-1);
			forced.insert(make_pair(-(a+1), b-1));
		} else adj[a-1].insert(b-1);
	}

	runRobot(0, 0);

	cout << counts << endl;
	return 0;
}