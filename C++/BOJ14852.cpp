// long 잘 사용!! => 수용할 수 있는 범위가 어디까지 인지 checking!
#include <iostream>
using namespace std;
int N;
long long int a[1000001];
long long int sum[1000000];

int main() {
	cin >> N;
	a[0] = 1;
	a[1] = 2;
	a[2] = 7;
	sum[0] = 1;

	for (int i = 3; i <= N; i++) {
		a[i] = (a[i - 1] * 2 + a[i - 2] * 3 + sum[i - 3] * 2)% 1000000007;
		sum[i - 2] = sum[i - 3] + a[i - 2];
	}
	cout << a[N];
	return 0;
}