#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef vector<int> vi;
vector<vi> board;

struct position {
	int file;
	int rank;
	int dist;
};


bool reachable(int i, int j) {
	if (i < 0 || j < 0|| i > 7 || j > 7) return false;
	if (board[i][j] == -1) return true;
	return false;
}

int main () {
	int tc, max;
	char file, rank;

	cin >> tc;
	while (tc--) {
		cin >> file >> rank;
		board.assign(8, vi(8, -1));
		max = 0;

		queue<position> q;
		q.push({file-'a', rank-'1', 0});
		while (!q.empty()) {
			int f = q.front().file;
			int r = q.front().rank;
			int d = q.front().dist;
			q.pop();
			board[f][r] = d;

			if (reachable(f-2, r-1)) q.push({f-2, r-1, board[f][r]+1});
			if (reachable(f-2, r+1)) q.push({f-2, r+1, board[f][r]+1});
			if (reachable(f+2, r-1)) q.push({f+2, r-1, board[f][r]+1});
			if (reachable(f+2, r+1)) q.push({f+2, r+1, board[f][r]+1});
			if (reachable(f-1, r-2)) q.push({f-1, r-2, board[f][r]+1});
			if (reachable(f+1, r-2)) q.push({f+1, r-2, board[f][r]+1});
			if (reachable(f+1, r+2)) q.push({f+1, r+2, board[f][r]+1});
			if (reachable(f-1, r+2)) q.push({f-1, r+2, board[f][r]+1});
		}

		for (auto &it : board) {
			for (auto &itt : it)
				if (itt > max) max = itt;
		}
		cout << max << " ";

        vector<string> out;
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if(board[i][j] == max) {
                    string s;
                    s += (char)(i+'a');
                    s += (char)(j+'1');
                    out.push_back(s);
                }
            }
        }

        sort(out.begin(), out.end(), [](string &a, string &b) {
			if (a[1] == b[1]) return a[0] < b[0];
			return a[1] > b[1];
        });

        for (auto &it : out) cout << it << " ";
       	cout << endl;
	}

	return 0;
}