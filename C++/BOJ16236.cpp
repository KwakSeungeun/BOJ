// 2�� �ð� + ���� ������ ����� ��� ��츦 üũ�� ���� ��찡 ����
// ó�� ���� �м��� �Ϻ��� �ϴ°� �߿�! && Ư���� ���̽��� �����ϸ� �ڵ��ϱ�
// weight�� 1�̶�� bfs()�� �ִܰ��
// bfs���� ó�� �߰��� �� ���� ����� ���� �ƴ� => ���� �� �ִ� ���� ��� ã�Ƶΰ�(vector�� ��Ƶα�) sort() ��, ��, ��, �� ��������!
// fish����ü ����� ���� ����
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int n, next_x, next_y;
int area[20][20];
bool visited[20][20];
int cur_size = 2;
int result = 0;
int cnt = 0;
const int dx[4] = {-1, 0, 0, 1}; //�� �� �� ��
const int dy[4] = {0,-1, 1, 0};

int bfs(int cx,int cy) {
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	vector<vector<int>> fish_loc(n, vector<int>(n, 0));
	queue<tuple<int, int, int>> q; // (x,y)
	int distance = 1;
	q.push(make_tuple(distance, cx, cy));
	visited[cx][cy] = true;
	int start_x = cx, start_y = cy, cd = distance;
	
	int nx, ny;
	bool flag = false;

	while (!q.empty()) {
		cd = get<0>(q.front());
		cx = get<1>(q.front());
		cy = get<2>(q.front());
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];
			if (nx <0 || nx>n - 1 || ny<0 || ny>n - 1) continue;
			if (!visited[nx][ny]) {
				if (area[nx][ny] >= 1 && area[nx][ny] < cur_size && area[nx][ny] != 9) { 
					flag = true;
					fish_loc[nx][ny] = cd;
					visited[nx][ny] = true;
				}
				else if (area[nx][ny] == 0 || area[nx][ny] == cur_size || area[nx][ny] == 9) {
					visited[nx][ny] = true;
					q.push(make_tuple(cd+1,nx, ny));
					distance++;
				}
			}
		}
	}
	int min = 2*n;
	if (flag) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (fish_loc[i][j] != 0) {
					if (min > fish_loc[i][j]) {
						next_x = i;
						next_y = j;
						min = fish_loc[i][j];
					}
				}
			}
		}
		area[next_x][next_y] = 0;
		cnt++;
		if (cnt == cur_size) {
			cnt = 0;
			cur_size++;
		}
	}
	if (flag) return min;
	else return 0;
}

void solution(int start_x, int start_y) {
	int cx = start_x, cy = start_y;
	int distance = 0;
	do {
		distance = bfs(cx, cy);
		result += distance;
		cx = next_x;
		cy = next_y;
	} while (distance != 0);
	return;
}

int main() {
	cin >> n;
	int temp = 0, x, y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			area[i][j] = temp;
			if (temp == 9) {
				x = i;
				y = j;
			}
		}
	}
	solution(x, y);
	cout << result;
	return 0;
}