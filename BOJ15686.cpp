// N과 M의 범위가 작기 때문에 하나하나 조합을 통해 해결 => 바이러스 문제와 비슷하게 해결
// 1. 치킨집 공간에 치킨집 위치 모두 저장해 둔다.
// 2. 저장된 치킨집 중에 M개를 선택하는 모든 경우의 수를 찾는다. (for문으로 하나씩 돌면서 재귀로 다시 나머지를 선택함)
// 3. M개가 선택된 경우 그때의 치킨거리 값을 계산해서 가지고 있는다.
// 4. 이를 반복하면서 치킨거리값이 가장 적게 나오는 것을 선택한다.
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int N, M; 
int area[51][51]; //1부터 작동
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