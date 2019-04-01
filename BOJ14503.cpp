#include <iostream>
using namespace std;

int area[51][51];
int N, M;
int result = 1;
int cnt = 0;
// 북, 동, 남, 서
const int dr[4] = { -1, 0, 1, 0 };
const int dc[4] = { 0, 1, 0, -1 };

void solution(int r, int c, int dir) {
	int next_r, next_c, next_d = dir, cnt=0;
	for (int i = 0; i < 4; i++) {
		next_d = (next_d + 3) % 4; // 왼쪽 회전
		next_r = r + dr[next_d];
		next_c = c + dc[next_d];
		if (next_r < 1 || next_r > N - 2 || next_c < 1 || next_c > M - 2 || area[next_r][next_c] != 0) {
			cnt++;
			continue;
		}
		else if (area[next_r][next_c] == 0) {
			area[next_r][next_c] = 2; // 청소한 영역
			result++;
			solution(next_r, next_c, next_d);
			break; //회전하고 이미 갔으니까 다른 방향 보는 것은 그만
		}
	}
	// 더 이상 없는 경우 후진
	if (cnt >= 4) {
		next_r = r + dr[(dir + 2) % 4];
		next_c = c + dc[(dir + 2) % 4];
		if (area[next_r][next_c] == 1) return;
		else {
			solution(next_r, next_c, dir);
			//return; => 이거 넣으면 틀림 why??
		}
	}
	return;
}

int main() { 
	cin >> N;
	cin >> M;
	int cur_r, cur_c, cur_dir;
	cin >> cur_r;
	cin >> cur_c;
	cin >> cur_dir;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> area[i][j];
		}
	}
	area[cur_r][cur_c] = 2;
	solution(cur_r, cur_c, cur_dir);
	cout << result;
	return 0;
}
