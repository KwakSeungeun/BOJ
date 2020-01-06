// �Ｚ SW���� ���� _ A��
#include <iostream>
#include <queue>
#define N 10
using namespace std;
int src[N][N];
bool visited[N][N] = {false};
int result;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0, 1, 0, -1 };
int availableNum[5] = { 5,5,5,5,5 };// index : 1x1...5x5 / value : ���� ���� ��
vector<vector<pair<int, int>>> group;

void attach(vector<pair<int, int>>& src,int size) {
	if (size < 0 || result < 0) {
		return;
	}
	else if (size == 1) { // 1x1 ������ ó��
		availableNum[0]--;
		if (availableNum[0] < 0) {
			result = -1;
			return;
		}
		else result++;
	}
	for (int i = 0; i < src.size(); i++) {

	}
	return;
}

int main() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> src[i][j];
		}
	}
	queue<pair<int, int>> q; // (x,y)
	vector<pair<int, int>> temp;

	int cx, cy, nx, ny;
	// group ���ϱ�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j]) continue;
			else if (src[i][j]==0) {
				visited[i][j] = true;
				continue;
			}
			q.push(make_pair(i,j));

			while (!q.empty())
			{
				cx = q.front().first;
				cy = q.front().second;
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					nx = cx + dx[dir];
					ny = cy + dy[dir];
					if (nx<0 || ny<0 || nx>N - 1 || ny>N - 1 || visited[nx][ny]) continue;
					if (src[nx][ny] == 1) { // 1�� ĭ ���簢�� üũ�� ��� �Ұ�?
						q.push(make_pair(nx, ny));
						visited[nx][ny] = true;
						temp.push_back(make_pair(nx, ny));
					}
				}
			}
			if (temp.size() > 0) { //group�� ����
				group.push_back(temp);
			}
			else if (!visited[i][j] && src[i][j] == 1) { // ���� 1���� �׷�
				temp.push_back(make_pair(i,j));
				group.push_back(temp);
				visited[i][j] = true;
			}
			temp.clear();
		}
	}
	
	// group���� ���鼭 ������ �ٿ�����
	for (int i = 0; i < group.size(); i++) {
		attach(group[i], 5);
		if (result < 0) break;
	}

	cout << result;
	cout << "\nGROUP �� : "<< group.size();
	return 0;
}