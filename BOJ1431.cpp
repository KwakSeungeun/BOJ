#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a[1000];

int getSum(string x) {
	int result = 0;
	for (int i = 0; i < x.length(); i++) {
		if (x[i]-'0' >= 0 && x[i]-'0' <= 9) {
			result += x[i]-'0';
		}
	}
	return result;
}

bool compare(string front, string second) {
	if (front.length() < second.length()) { return 1; }
	else if (front.length() > second.length()) { return 0; }
	else {
		int sumA = getSum(front);
		int sumB = getSum(second);
		if (sumA < sumB) return 1;
		else if (sumA > sumB) return 0;
		else {
			return front < second;
		}
	}
}

int main() {
	int N;
	cin >> N;
	string input;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	sort(a,a+N,compare);

	for (int i = 0; i < N; i++) {
		cout << a[i] << endl;
	}

	return 0;
}