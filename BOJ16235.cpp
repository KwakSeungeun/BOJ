#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
int a[11][11]; // 1부터 시작, 겨울에 추가할 양분정보 
int area[11][11]; // 토양정보
// 생성시 tree();이렇게 하고 싶으면 생성자가 필요!
struct tree {
	int x;
	int y;
	int age;
};
// vector는 erase O(n) => 빠르게 할 수 있는 dequeue or list 사용
vector<tree> myTree; // 가지고 있는 나무 정보
vector<tree> deadTrees; //죽은 나무

const int dx[8] = { -1,-1,-1,0,0,1,1,1 };
const int dy[8] = { -1,0,1,-1,1,-1,0,1 };

// 좌표 , 나이 순으로 비교
bool compareTree(tree a, tree b) {
	return a.age > b.age;
}

void spring() {
	int cx, cy, age;
	for (int i = 0; i < myTree.size(); i++) {
		cx = myTree[i].x;
		cy = myTree[i].y;
		age = myTree[i].age;
		if (age <= area[cx][cy]) { // 양분 먹기 성공
			area[cx][cy] -= age;
			myTree[i].age++;
		} else { 
			deadTrees.push_back(myTree[i]);
			myTree.erase(myTree.begin() + i);
			i--; //제자리
		}
	}
	return;
}

void summer(){
	for (int i = 0; i < deadTrees.size(); i++) {
		area[deadTrees[i].x][deadTrees[i].y] += (deadTrees[i].age / 2);
		deadTrees.pop_back();
	}
	return;
}

void fall() {
	int size = myTree.size();
	tree curTree;
	int x, y;
	for (int i = 0; i < size; i++) {
		curTree = myTree[i];
		if (curTree.age % 5 == 0) {
			for (int cnt = 0; cnt < 8; cnt++) {
				x = curTree.x + dx[cnt];
				y = curTree.y + dy[cnt];
				if (x<1 || x>n || y<1 || y>n) continue;
				myTree.push_back(tree{ x,y,1 });
			}
		}
	}
	return;
}

void winter() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			area[i][j] += a[i][j];
		}
	}
	return;
}

int main() {
	cin >> n;
	cin >> m;
	cin >> k; // nxn : 영역 ,m: 처음심은 나무 수, k: 몇년 후
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			area[i][j] = 5; //처음 땅에는 모두 5를 가지고 있음
		}
	}
	int x, y, z;
	for (int i = 0; i < m; i++) {
		cin >> x;
		cin >> y;
		cin >> z;
		myTree.push_back(tree{ x,y,z });
	}

	sort(myTree.begin(), myTree.end(), compareTree);
	for (int i = 0; i < k; i++) {
		spring();
		summer();
		fall();
		winter();
	}

	cout << myTree.size();
	return 0;
}