// 시간초과를 해결하기 위해 counting sort 사용 
// 그러나 케이스통과는 하지 못함.
#include <iostream>
using namespace std;

int a[10001] = { 0 };

int main() {
	int N;
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		a[temp]++;
	}

	for (int i = 1; i <= 10000; i++) {
		while (a[i] != 0) {
			cout << i << endl;
			a[i]--;
		}
	}
	return 0;
}