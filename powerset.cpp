#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
	if (argc < 2) {
		cerr << "Usage: " << argv[0] << " words.txt\n";
		return 1;
	}

	ifstream fin;
	fin.open(argv[1]);
	if (!fin) { 
		cerr << "Cannot open " << argv[1] << endl; 
		return 1; 
	}

	vector<string> items;
	string line;
	while (getline(fin, line)) {
		items.push_back(line);
	}
	fin.close();

	int n = (int)items.size();

	//iterate all non-empty masks from 1 .. 2^n-1
	int maxmask = (1 << n);
	for (int mask = 1; mask < maxmask; mask++) {
		//build and print one line
		for (int i = 0; i < n; i++) {
			if (mask & (1 << i)) {
				cout << items[i];
			}
		}
		cout << endl;
	}

	return 0;
}

