#include <iostream>
#include <vector>
using namespace std;

vector<vector<char> > islands;
int counts = 0;

void dfs(int i, int j, int n, int m) {
    if (i < 0 || j < 0 || i == n || j == m) return;
    if (islands[i][j] == 'W') return;
    islands[i][j] = 'W';
    dfs(i, j-1, n, m);
    dfs(i, j+1, n, m);
    dfs(i-1, j, n, m);
    dfs(i+1, j, n, m);
}

int main () {
    int n, m;
    
    cin >> n >> m;
    islands.assign(n, vector<char>(m, 'C'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> islands[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (islands[i][j] == 'L') {
                dfs(i, j, n, m);
                counts++;
            }
        }
    }
    
    cout << counts << endl;
    return 0;
}