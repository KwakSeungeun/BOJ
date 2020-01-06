#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> area(8, vector<int>(8));
vector<vector<int>> temp(8, vector<int>(8));
int result = 0;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

void spreadVirus(vector<vector<int>> spreaded_area) {
	queue<pair<int, int>> q; 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (spreaded_area[i][j] == 2) q.push(pair<int, int>(i, j));
		}
	}
	int curX, curY, curVal;
	while (!q.empty()) {
		curX = q.front().first;
		curY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)	continue;
			if (spreaded_area[nextX][nextY] == 0) {
				q.push(pair<int, int>(nextX, nextY));
				spreaded_area[nextX][nextY] = 2;
			}
		}
	}

	int safe_area = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (spreaded_area[i][j] == 0) safe_area++;
		}
	}
	result = max(result, safe_area);
}

void makeWall(int cnt){
	if (cnt == 3){
		spreadVirus(temp);
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (temp[i][j] == 0){
				temp[i][j] = 1;
				makeWall(cnt + 1);
				temp[i][j] = 0;
			}
		}
	}
}

int main() {
	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> area[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (area[i][j] == 0){
				for (int k = 0; k < N; k++) {
					for (int l = 0; l < M; l++) {
						temp[k][l] = area[k][l];
					}
				}
				temp[i][j] = 1;
				makeWall(1);
				temp[i][j] = 0;
			}
		}
	}
	cout << result;
	return 0;
}