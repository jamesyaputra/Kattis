#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <unordered_map>
using namespace std;

vector<vector<string> > v;
vector<string> att;
unordered_map<string, int> order;

int main () {
    int counts = 0, n;
    string attributes, token;
    
    getline(cin, attributes);
    istringstream iss(attributes);
    
    while(iss >> token) {
        order[token] = counts++;
        att.push_back(token);
    }
    
    cin >> n;
    v.assign(n, vector<string>());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < counts; j++) {
            string in;
            cin >> in;
            v[i].push_back(in);
        }
    }
    
    cin >> n;
    while (n--) {
        string in;
        int index;
        cin >> in;
        index = order[in];
        
        for (auto &it : v)
            swap(it[0], it[index]);
        
        stable_sort(v.begin(), v.end(), [](vector<string> a, vector<string> b) {
            return a[0] < b[0];
        });
        
        for (auto &it : v)
            swap(it[0], it[index]); 

        for (auto &it : att)
            cout << it << " ";
        
        cout << endl;
        
        for (auto &it : v) {
            for (auto &itt : it) cout << itt << " ";
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}