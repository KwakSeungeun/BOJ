// .clear()는 단순히 삭제만 해주는 것 ! 그래서 이걸로 비어있는지 확인하려면 .empty()x .size로 판단하기!
// group!! =>  이중 for문으로 계속 돌고 거기서 bfs/dfs로 순환하며 group을 찾고 (조건에 맞는 경우만 visitied true and )
// 2차원 vector사용시 임시로 list만들어 줘서 넣어줘도 됨!
// 순차적인 실행에 대해 고민해보기
#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;
int N, L, R, move_cnt;
int a[50][50];
const int dx[4] = { -1, 0, 1,0 };//  상 우 하 좌
const int dy[4] = { 0,1,0,-1 };
struct Node {
	int x, y, people;
	Node(int _x, int _y, int _people) { x = _x, y = _y, people = _people; };
};
vector<vector<Node>> group;
vector<Node> temp{};
bool flag = true;

void openGate() {
	// 모든 Node기준으로 check!
	vector<vector<bool>> visited(N, vector<bool>(N, false));
	queue<Node> q;

	int cx, cy, cp, nx, ny;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j]) continue;
			q.push(Node(i, j, a[i][j]));

			while (!q.empty()) {
				cx = q.front().x;
				cy = q.front().y;
				cp = q.front().people;
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					nx = cx + dx[dir];
					ny = cy + dy[dir];
					if (nx<0 || ny<0 || nx>N - 1 || ny>N - 1 || visited[nx][ny]) continue;
					int gap = abs(cp - a[nx][ny]);
					if (L <= gap && gap <= R) { //연합이 될 수 있음
						visited[nx][ny] = true;
						q.push(Node(nx, ny, a[nx][ny]));
						temp.push_back(Node(nx, ny, a[nx][ny]));
					}
				}
			}
		
			if (!temp.empty()) {
				group.push_back(temp);
				temp.clear();
			}
		}
	}
	
	return;
}

// 조건에 맞게 연합들을 
void move() {
	if (group.size() == 0) {
		flag = false;
		return;
	}
	int sum, res, num;
	for (int i = 0; i < group.size(); i++) {
		sum = 0, res = 0;
		num = group[i].size();
		if (num <= 0) break;
		for (int j = 0; j < num; j++) {
			sum += a[group[i][j].x][group[i][j].y];
		}
		res = sum / num;
		for (int j = 0; j < num; j++) {
			a[group[i][j].x][group[i][j].y] = res;
		}
	}
	group.clear();
	move_cnt++;
	return;
}

int main() {
	cin >> N;
	cin >> L;
	cin >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}
	while (flag) {
		openGate();
		move();
	}
		
	cout << move_cnt;
	return 0;
}