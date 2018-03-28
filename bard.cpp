#include <iostream>
#include <stack>
#include <vector>
#include <set>
using namespace std;

int main () {
	int villagers, nights;
	int num, x;
	int song_id = 0;
	bool bard_here;
	vector<int> tonight;
	vector<set<int> > know_songs;

	cin >> villagers >> nights;
	know_songs.assign(villagers, set<int>());
	while (nights--) {
		cin >> num;
		bard_here = false;
		tonight.clear();
		for (int i = 0; i < num; i++) {
			cin >> x;
			if (x == 1) {
				bard_here = true;
			} else tonight.push_back(x-1);
		}
		
		if (bard_here) {
			song_id++;
			for (int i = 0; i < num-1; i++) know_songs[tonight[i]].insert(song_id);
		} else {
			for (int i = 0; i < tonight.size(); i++) {
				for (auto &it : know_songs[tonight[i]]) {
					for (int j = 0; j < tonight.size(); j++) {
						know_songs[tonight[j]].insert(it);
					}
				}
			}
		}

	}

	cout << 1 << endl;
	for (int i = 1; i < villagers; i++) {
		if (know_songs[i].size() == song_id) cout << i+1 << endl;
	}

	return 0;
}