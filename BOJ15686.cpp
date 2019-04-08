// N�� M�� ������ �۱� ������ �ϳ��ϳ� ������ ���� �ذ� => ���̷��� ������ ����ϰ� �ذ�
// 1. ġŲ�� ������ ġŲ�� ��ġ ��� ������ �д�.
// 2. ����� ġŲ�� �߿� M���� �����ϴ� ��� ����� ���� ã�´�. (for������ �ϳ��� ���鼭 ��ͷ� �ٽ� �������� ������)
// 3. M���� ���õ� ��� �׶��� ġŲ�Ÿ� ���� ����ؼ� ������ �ִ´�.
// 4. �̸� �ݺ��ϸ鼭 ġŲ�Ÿ����� ���� ���� ������ ���� �����Ѵ�.
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int N, M; 
int area[51][51]; //1���� �۵�
int result = 2000;
vector<pair<int, int>> houses; // (x,y)
vector<pair<int, int>> stores;
vector<pair<int, int>> temp;


int getDistance() {
	int cx, cy,dx,dy ,res = 0, distance;
	for (int i = 0; i < houses.size(); i++) {
		cx = houses[i].first;
		cy = houses[i].second;
		distance = 1000;
		for (int j = 0; j < temp.size(); j++) {
			dx = temp[j].first;
			dy = temp[j].second;
			int temp_dis = abs(cx-dx) + abs(cy-dy);
			if (distance > temp_dis) distance = temp_dis;
		}
		res += distance;
	}
	return res;
}

void selectStore(int cnt, int startIndex) {
	if (cnt == M) {
		int dis = getDistance();
		if (result > dis) result = dis;
		return;
	}
	for (int i = startIndex; i < stores.size();i++) {
		temp.push_back(stores[i]);
		selectStore(cnt + 1, i + 1);
		temp.pop_back();
	}
	return;
}

int main() {
	cin >> N;
	cin >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> area[i][j];
			if (area[i][j] == 1) houses.push_back(make_pair(i, j));
			else if (area[i][j] == 2) stores.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < stores.size(); i++) {
		temp.push_back(stores[i]);
		selectStore(1, i+1);
		temp.clear();
	}
	cout << result;
	cout << INT_MAX;
	return 0;
}