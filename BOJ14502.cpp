#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, result;
int dirX[4] = {0,1,0,-1};
int dirY[4] = {1,0,-1,0};
struct Node {
	int val;
	int x, y;
};

int count(vector<vector<Node>> src) {
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (src[i][j].val == 0) count++;
		}
	}
	return count;
}


void print(vector<vector<Node>> src) {
	cout << "------------------------------------\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << src[i][j].val << " ";
		}
		cout << "\n";
	}
}

void spread(vector<vector<Node>> &src, int srcX, int srcY, int size, int row, int col ) {
	for (int k = 1; k < size; k++) {
		int x = srcX + k * row;
		int y = srcY + k * col;
		if (x < 0 || x >= N || y < 0 || y >= N) continue;

		if (src[x][y].val != 1) {
			src[x][y].val = 2;
		}
		else if (src[x][y].val == 1) {
			return;
		}
	}
}

// 바이러스 퍼짐
int getSafeArea(vector<vector<Node>> src) {
	vector<vector<bool>> visited(N, vector<bool>(M, false));
	queue<Node> q;

	q.push(src[0][0]);
	visited[0][0] = true;

	Node curNode;
	while (!q.empty()) {
		curNode = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x = curNode.x + dirX[i];
			int y = curNode.y + dirY[i];
			if (x < 0 || x >= N || y < 0 || y >= N) continue;
			if (!visited[x][y]) {
				q.push(src[x][y]);
				visited[x][y] = true;
				if (src[x][y].val == 2) {
					// 상하좌우로 퍼져나감
					for (int k = 0; k < 4; k++) {
						if(dirX[k] == 0) spread(src, x, y,N, dirX[k], dirY[k]);
						else spread(src, x, y, M, dirX[k], dirY[k]);
					}
				}
			}
		}
	}
	print(src);
	return count(src);
}

// 0위치에 벽 세개 세우기
void solution(vector<vector<Node>> src) {
	vector<vector<bool>> visited(N, vector<bool>(M, false));
	queue<Node> q;

	q.push(src[0][0]);
	visited[0][0] = true;

	Node curNode;
	int wallCount = 0;
	while (!q.empty()){
		curNode = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x = curNode.x + dirX[i];
			int y = curNode.y + dirY[i];
			if (x < 0 || x >= N || y < 0 || y >= N) continue;
			if (!visited[x][y]) {
				q.push(src[x][y]);
				visited[x][y] = true;
				if (src[x][y].val == 0) {
					wallCount++;
					src[x][y].val = 1;
					if (wallCount >= 3) break;
				}
			}
		}
		if (wallCount >= 3) break;
	}
	print(src);
	result = getSafeArea(src);
}

int main() {
	cin >> N >> M;
	int temp = -1;
	vector<vector<Node>> area(N);

	for (int i = 0; i < N; i++) {
;		for (int j = 0; j < M; j++) {
			cin >> temp;
			area[i].push_back(Node{ temp, i, j });
		}
	}
	solution(area);
	cout << result;
	return 0;
}