#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main () {
	int test;
	vector<string> input, sound, output;
	string in;
	cin >> test;
	
	for (int i = 0; i < test; i++) {
		input.clear();
		sound.clear();
		output.clear();
		do {
			cin >> in;
			input.push_back(in);
		} while (cin.get() != '\n');

		string token;
		do {
			cin >> in;
			istringstream ss(in);
			while(getline(ss, token)) {
				if (token == "say?") break;
				else if (token == "goes") {
					cin >> in;
					sound.push_back(in);
				}
			}
		} while (token != "say?");
		
		int flag;
		for (int j = 0; j < input.size(); j++) {
			flag = 0;
			for (int k = 0; k < sound.size(); k++) {
				if (input[j] == sound[k]) flag = 1;
			}
			if (!flag) {
				output.push_back(input[j]);
			}
		}

		for (int j = 0; j < output.size(); j++) {
			cout << output[j] << " ";
		}
		cout << endl;
	}

	return 0;
}