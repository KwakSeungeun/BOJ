// 17070 틀림 , 17069 메모리초과
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int N, result;
const int dx[] = { 0, 1, 1 };
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
	queue<tuple<int, int,int>> q;
	q.push(make_tuple(0,0,1));
	int cur_mode, cur_x,cur_y, next_x, next_y;
	while (!q.empty()) {
		cur_mode = get<0>(q.front());
		cur_x = get<1>(q.front());
		cur_y = get<2>(q.front());
		q.pop();
		for (int k = 0; k < 3; k++) {
			if ((k == 0 && cur_mode == 2) || (k == 2 && cur_mode == 0)) continue;
			next_x = cur_x + dx[k];
			next_y = cur_y + dy[k];
			if (next_x == N - 1 && next_y == N - 1) {
				result++;
				continue;
			} else if (next_x > N - 1 || next_y > N - 1) {
				continue;
			}
			if (src[next_x][next_y] ||(k == 1 && (src[next_x - 1][next_y] || src[next_x][next_y - 1]))) continue;
			q.push(make_tuple(k,next_x, next_y)); 
		}
	}
	cout << result;
	return 0;
}