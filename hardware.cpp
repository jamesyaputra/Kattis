#include <iostream>
#include<sstream>
#include <vector>
#include <string>
using namespace std;

vector<int> counts;

void digits(string in) {
	for (int i = 0; i < in.size(); i++) {
		counts[in[i]-'0']++;
	}
}

int main () {
	int orders;

	cin >> orders;
	while (orders--) {
		string name, dump;
		int num;
		cin.ignore();
		getline(cin, name);
		cin >> num >> dump;

		int i = 0;
		counts.assign(10, 0);
		while (i < num) {
			string in;
			cin >> in;
			if (in != "+") {
				digits(in);
				i++;
			} else {
				int multiple[3];
				for (int i = 0; i < 3; i++) {
					cin >> multiple[i];
				}

				int k = multiple[1];
				while (k >= multiple[0]) {
					digits(to_string(k));
					k -= multiple[2];
					i++;
				}
			}
		}

		cout << name << endl;
		cout << num << " " << dump << endl;
		int sum = 0;
		for (int l = 0; l < 10; l++) {
			cout << "Make " << counts[l] << " digit " << l << endl;
			sum += counts[l];
		}
		cout << "In total " << sum << " digit";
		if (sum > 1) cout << "s";
		cout << endl;
	}

	return 0;
}
