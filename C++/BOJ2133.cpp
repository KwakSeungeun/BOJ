#include <iostream>
using namespace std;
int s[31];

// ¦���� ���� ������ ��� Sn-2*2 ���� ���ܳ�!!!(��, �ߺ����� ���ο� ������ ���ܳ�!!)
// Ÿ�ϸ� �� �� ���� ���� ������ ��� ã�� ���� �߿�!
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