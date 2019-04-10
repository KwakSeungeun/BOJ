// ��ȭ���� �� �����
// ��Ģ�� �� ã��
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node {
	int x, y, d, g;
	Node(int _x, int _y, int _d, int _g) {
		x = _x, y = _y, d = _d, g = _g;
	}
};
int N, result;
const int dx[4] = { 0,-1,0,1 }; //d ���� - �� �� �� �� (x�� ����, y�� ����)
const int dy[4] = { 1,0,-1,0 };
int area[101][101] = {0};
vector<Node> curves;
vector<int> rotatedCurves;

void print() {
	cout << "\n";
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			cout << area[i][j] <<" ";
		}
		cout << "\n";
	}
	cout << "\n";
}
int test = 1;
void solution(int x, int y , int d, int g) {
	if (g <= 0) return; // 0���� �ΰ�� �̹� �տ��� �� ó��
	for (int i = 1; i <= g; i++) { // 1���� ���� ó��
		int size = rotatedCurves.size();
		for (int j = size-1; j >= 0; j--) {
			d = rotatedCurves[j];
			x += dx[d];
			y += dy[d];
			area[x][y] = test;
			int temp = (d + 1) % 4; //90�� ȸ���ؼ� ���� ������ �ֱ�
			rotatedCurves.push_back(temp);
		}
	}
	test++;
	return;
}

int main() {
	cin >> N;
	int x, y, d, g;
	for (int i = 0; i < N; i++) {
		cin >> y;
		cin >> x; // ��� ���� x,y �� �ݴ� �̹Ƿ� �Ųٷ� �Է¹ޱ�
		cin >> d;
		cin >> g;
		curves.push_back(Node(x,y,d,g));
	}
	Node cur(0,0,0,0);
	int nextDir, nx, ny;
	for (int j = 0; j < N; j++) {
		cur = curves[j];
		// 0���� ����� �ֱ�
		area[cur.x][cur.y] = test;
		nx = cur.x + dx[cur.d];
		ny = cur.y + dy[cur.d];
		area[nx][ny] = test;
		// stack�� 0���븦 90�� ���� ���� �־�α�
		nextDir = (cur.d + 1) % 4;
		rotatedCurves.push_back(nextDir);
		// 1���� �̻��� Ŀ�� ����� �ִ°�
		solution(nx, ny, cur.d, cur.g);
		rotatedCurves.clear();
		//print();

	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (area[i][j] && area[i + 1][j] && area[i][j + 1] && area[i + 1][j + 1]) result++;
		}
	}
	cout << result;
	return 0;
}