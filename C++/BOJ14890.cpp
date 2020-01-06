#include <iostream>
using namespace std;
int N, L;
int graph[100][100];
int transGraph[100][100];
int cnt;

void solution(int src[][100]) {
	int cur, next;
	int len = 1;
	for (int i = 0; i < N; i++) {
		len = 1;
		for (int j = 0; j < N; j++) {
			if (j == N-1) {
				cnt++;
				break;
			}
			cur = src[i][j];
			next = src[i][j + 1];
			if (cur == next) len++;
			// 오르막
			else if (cur + 1 == next) {
				if (len >= L) { 
					len = 1;
				}
				else break;
			} 
			// 내리막
			else if (cur == next + 1) {
				if (j == N - 2 && L != 1) break;
				else if (j == N - 2 && L == 1) { 
					cnt++; 
					break;
				}

				int index = 1;
				while (next == src[i][j + 1 + index]) index++;
				if (index > L || (index == L && next >= src[i][j + 1 + index])) { 
					j = j + L;
					if (j == N - 1) {
						cnt++;
						break;
					}
				}
				else break;
			}
			else break;
		}
	}
}

int main() {
	cin >> N;
	cin >> L;

	int temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> temp;
			graph[i][j] = temp;
			transGraph[j][i] = temp;
		}
	}
	solution(graph);
	solution(transGraph);

	cout << cnt << endl;
	return 0;
}