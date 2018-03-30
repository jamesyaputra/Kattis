#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

typedef unordered_set<int> si;
vector<si> all;
vector<int> size;
queue<int> q;

void domino (int source) {
    for (auto &it : all[source]) {
        all[it].erase(source);
        q.push(it);
    }
    all[source].clear();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int c, p, x, l;
    
    cin >> c >> p >> x >> l;
    all.assign(c, si());
    for (int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;
        all[a-1].insert(b-1);
        all[b-1].insert(a-1);
    }
    
    for (int i = 0; i < c; i++) 
        size.push_back((int)all[i].size());

    domino(l-1);
    while(!q.empty()) {
        if (all[q.front()].size() <= size[q.front()]/2 && !all[q.front()].empty()) domino(q.front());
        q.pop();
    }
    
    if (all[x-1].empty()) cout << "leave";
    else cout << "stay";
    cout << endl;
    
    return 0;
}