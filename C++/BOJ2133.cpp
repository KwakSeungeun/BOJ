#include <iostream>
using namespace std;
int s[31];

// 짝수개 마다 고유한 모양 Sn-2*2 개로 생겨남!!!(즉, 중복없이 새로운 도형이 생겨남!!)
// 타일링 할 때 가장 작은 고유한 모양 찾는 것이 중요!
int main() {
	int N;
	cin >> N;
	s[0] = 1;
	s[2] = 3;
	int k;
	for (int i = 3; i <= N; i++) {
		s[i] = s[i - 2] * 3;
		k = 4;
		while (i-k >=0) {
			s[i] += s[i - k] * 2;
			k += 2;
		}
	}
	cout << s[N];
	return 0;
}