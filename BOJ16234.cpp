// .clear()�� �ܼ��� ������ ���ִ� �� ! �׷��� �̰ɷ� ����ִ��� Ȯ���Ϸ��� .empty()x .size�� �Ǵ��ϱ�!
// group!! =>  ���� for������ ��� ���� �ű⼭ bfs/dfs�� ��ȯ�ϸ� group�� ã�� (���ǿ� �´� ��츸 visitied true and )
// 2���� vector���� �ӽ÷� list����� �༭ �־��൵ ��!
// �������� ���࿡ ���� ����غ���
#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;
int N, L, R, move_cnt;
int a[50][50];
const int dx[4] = { -1, 0, 1,0 };//  �� �� �� ��
const int dy[4] = { 0,1,0,-1 };
struct Node {
	int x, y, people;
	Node(int _x, int _y, int _people) { x = _x, y = _y, people = _people; };
};
vector<vector<Node>> group;
vector<Node> temp{};
bool flag = true;

void openGate() {
	// ��� Node�������� check!
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
					if (L <= gap && gap <= R) { //������ �� �� ����
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

// ���ǿ� �°� ���յ��� 
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