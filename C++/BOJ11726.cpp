#include <iostream>
using namespace std;
int N;
int s[1001];

int findCases(int x) {
	if (x == 1) return 1;
	else if (x == 2) return 2;

	if (s[x] != 0) return s[x];
	return s[x] = (findCases(x-1) +  findCases(x-2))%10007;
}

int main() {
	cin >> N;
	s[1] = 1;
	s[2] = 2;
	cout << findCases(N);
	return 0;
}