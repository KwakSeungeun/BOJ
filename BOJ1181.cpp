#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void print(vector<string> src) {
	for (int i = 0; i < src.size(); i++) {
		cout << src[i] << endl;
	}
}

bool compare(string a , string b) {
	if (a.length() < b.length()) {
		return 1;
	} else if (a.length() > b.length()) {
		return 0;
	} else {
		return a < b;
	}
}

int main(void) {
	int N;
	cin >> N;
	vector<string> src;
	
	string input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		src.push_back(input);
	}

	sort(src.begin(), src.end(), compare); 
	src.erase(unique(src.begin(), src.end()),src.end()); //중복 제거 O(N)

	print(src);
	return 0;
}