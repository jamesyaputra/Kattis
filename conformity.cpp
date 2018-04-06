#include <iostream>
#include<map>
#include <set>
using namespace std;
int main () {
	int n, sum = 0, a;
	map<set<int>, int> mm;
	cin >> n;
	for (int i = 0; i < n; i++) {
		set<int> s;
		for (int j = 0; j < 5; j++) {
			cin >> a;
			s.insert(a);
		}
		mm[s]++;
	}
	set<int> se;
	for (auto &it : mm) se.insert(it.second);
	auto max = se.rbegin();
	for (auto &it: mm) if (it.second == *max) sum += *max;
	cout << sum << endl;
	return 0;
}