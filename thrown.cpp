#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main () {
	int children, t;
	int track = 0;
	string input;
	stack<int> s;

	cin >> children >> t;
	for (int i = 0; i < t; i++) {
		cin >> input;

		if (input == "undo") {
			int cmd;
			cin >> cmd;
			while(cmd--) {
				if (!s.empty()) s.pop();
			}
			if (!s.empty()) track = s.top();
			else track = 0;
		} else {
			track += stoi(input);
			if (track >= 0) track = track%children;
			else if (track < 0) track = (children + track%children)%children;
			else if (!(stoi(input)%children)) track += 0; 
			s.push(track);
		}
	}
	if (s.empty()) cout << 0 << endl;
	else cout << s.top() << endl;
	return 0;
}