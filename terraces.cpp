#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
vector<vi> terraces;
vector<vi> visited;
int sizes = 0;
bool flow = false;

void dfs(int i, int j, int n, int m, int height) {
    if (i < 0 || j < 0 || i == n || j == m) return;
    if (height != -1 && terraces[i][j] > height) return;
    if (height != -1 && height > terraces[i][j]) {
        flow = true;
        return;
    }
    if (visited[i][j]) return;
    
    if (height == -1) height = terraces[i][j];
    sizes++;
    visited[i][j] = 1;
    
    dfs(i+1, j, n, m, height);
    dfs(i-1, j, n, m, height);
    dfs(i, j+1, n, m, height);
    dfs(i, j-1, n, m, height);
}

int main () {
    int n, m;
    int out = 0;
    
    cin >> m >> n;
    terraces.assign(n, vi(m, 0));
    visited.assign(n, vi(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> terraces[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                sizes = 0;
                flow = false;
                dfs(i, j, n, m, -1);
                if (!flow) {
                    out += sizes;
                }
            }
        }
    }

    cout << out << endl;
    return 0;
}