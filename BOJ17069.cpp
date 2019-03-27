#include <iostream>
#include <queue>
#include <vector>
#define ROW 0
#define DIAGONAL 1 
#define COL 2
using namespace std;

int N, result;
struct Pipe{
	int x, y, mode;
};
const int dx[] = {0, 1, 1};
const int dy[] = { 1, 1, 0 };

int main() {
	cin >> N;
	vector<vector<bool>> src(N);
	bool temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> temp;
			src[i].push_back(temp);
		}
	}
	queue<Pipe> q;
	q.push({ 0,1, ROW });
	Pipe cur;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int k = 0; k < 3; k++) {
			if ((cur.mode == ROW && k == 2) || (cur.mode == COL && k == 0)) continue;
			Pipe next = { cur.x + dx[k], cur.y + dy[k], k };
			if (next.x > N - 1 || next.y > N - 1) continue;
			if (src[next.x][next.y] == false) {
				if (next.mode == DIAGONAL && (src[next.x - 1][next.y] != 0 || src[next.x][next.y - 1] != 0)) continue;
				q.push(next);
				if (next.x == N-1 && next.y == N-1) {
					result++;
					continue;
				}
			}

		}
	}
	cout << result;
	return 0;
}