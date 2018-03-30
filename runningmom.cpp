#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

unordered_map<string, vector<string> > m;
unordered_map<string, int> visited;
bool back_edge = false;

void dfs (string source) {
    visited[source] = 1;
    
    for (auto &it : m[source]) {
        if (!visited[it]) dfs(it);
        else if(visited[it] == 1) {
            back_edge = true;
            break;
        }
    }
    if (back_edge) return;
    visited[source] = 2;
}

int main () {
    string origin, dest;
    int n;
    
    cin >> n;
    while (n--) {
        cin >> origin >> dest;
        m[origin].push_back(dest);
    }
    
    while (cin >> origin) {
        visited.clear();
        back_edge = false;
        cout << origin << " ";
        dfs(origin);
        if(back_edge) cout << "safe";
        else cout << "trapped";
        cout << endl;
    }
    return 0;
}