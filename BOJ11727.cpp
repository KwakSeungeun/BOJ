#include <iostream>
using namespace std;
int s[1001];

int main() {
	int N;
	cin >> N;
	s[1] = 1;
	s[2] = 3;
	for (int i = 3; i <= N; i++) {
		s[i] = (s[i - 1] + s[i - 2]*2) % 10007;
	}
	cout << s[N];
	return 0;
}

// 중복 되는 부분들 잘 생각하기!