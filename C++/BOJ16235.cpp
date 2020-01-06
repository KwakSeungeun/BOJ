// list, deque, vector 상황에 맞춰 잘 사용하기
// sort를 매 for문마다 해주는 것은 비효율적! 이에 대해 고민해보기
// 리스트, 배열, 덱에 중간에 추가(삭제)할경우 index처리 잘해주기
#include <iostream>
#include <deque>
#include <list>
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
	bool operator<(tree other) {
		return age < other.age;
	}
};
// vector는 erase O(n) => 빠르게 할 수 있는 dequeue or list 사용	
list<tree> myTree; // 가지고 있는 나무 정보 => List => iterator사용해야함!!
deque<tree> deadTrees; //죽은 나무 => 중간 안지우니까 dequeue사용

const int dx[8] = { -1,-1,-1,0,0,1,1,1 };
const int dy[8] = { -1,0,1,-1,1,-1,0,1 };

// 좌표 , 나이 순으로 비교
bool compareTree(tree a, tree b) {
	return a.age > b.age;
}

void spring() {
	tree curTree;
	for (list<tree>::iterator itr = myTree.begin(); itr != myTree.end(); itr++) {
		curTree = *itr;
		if (curTree.age <= area[curTree.x][curTree.y]) { // 양분 먹기 성공
			area[curTree.x][curTree.y] -= curTree.age;
			itr->age += 1;
		}
		else {
			deadTrees.push_back(curTree);
			myTree.erase(itr--);
			// itr--; error (int형이 아님!!)
		}
	}	
	return;
}

void summer(){
	for (int i = 0; i < deadTrees.size(); i++) {
		area[deadTrees[i].x][deadTrees[i].y] += (deadTrees[i].age / 2);
	}
	deadTrees.clear(); //for문에서 삭제하면 i로 접근하는게 이상하기때문에 나중에 하거나 i--를 해줘야함!!
	return;
}

void fall() {
	tree curTree;
	int x, y;
	for (list<tree>::iterator itr = myTree.begin(); itr != myTree.end(); itr++) {
		curTree = *itr;
		if (curTree.age % 5 == 0) {
			for (int cnt = 0; cnt < 8; cnt++) {
				x = curTree.x + dx[cnt];
				y = curTree.y + dy[cnt];
				if (x<1 || x>n || y<1 || y>n) continue;
				myTree.push_front(tree{ x,y,1 });
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

	//sort(myTree.begin(), myTree.end(), compareTree); List는 []임이의 원소 접근이 불가하기떄문에 sort함수 사용 불가능
	myTree.sort();
	for (int i = 0; i < k; i++) {
		spring();
		summer();
		fall();
		winter();
	}

	cout << myTree.size();
	return 0;
}