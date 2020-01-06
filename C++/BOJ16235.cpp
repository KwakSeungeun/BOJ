// list, deque, vector ��Ȳ�� ���� �� ����ϱ�
// sort�� �� for������ ���ִ� ���� ��ȿ����! �̿� ���� ����غ���
// ����Ʈ, �迭, ���� �߰��� �߰�(����)�Ұ�� indexó�� �����ֱ�
#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
using namespace std;

int n, m, k;
int a[11][11]; // 1���� ����, �ܿ￡ �߰��� ������� 
int area[11][11]; // �������
// ������ tree();�̷��� �ϰ� ������ �����ڰ� �ʿ�!
struct tree {
	int x;
	int y;
	int age;
	bool operator<(tree other) {
		return age < other.age;
	}
};
// vector�� erase O(n) => ������ �� �� �ִ� dequeue or list ���	
list<tree> myTree; // ������ �ִ� ���� ���� => List => iterator����ؾ���!!
deque<tree> deadTrees; //���� ���� => �߰� ������ϱ� dequeue���

const int dx[8] = { -1,-1,-1,0,0,1,1,1 };
const int dy[8] = { -1,0,1,-1,1,-1,0,1 };

// ��ǥ , ���� ������ ��
bool compareTree(tree a, tree b) {
	return a.age > b.age;
}

void spring() {
	tree curTree;
	for (list<tree>::iterator itr = myTree.begin(); itr != myTree.end(); itr++) {
		curTree = *itr;
		if (curTree.age <= area[curTree.x][curTree.y]) { // ��� �Ա� ����
			area[curTree.x][curTree.y] -= curTree.age;
			itr->age += 1;
		}
		else {
			deadTrees.push_back(curTree);
			myTree.erase(itr--);
			// itr--; error (int���� �ƴ�!!)
		}
	}	
	return;
}

void summer(){
	for (int i = 0; i < deadTrees.size(); i++) {
		area[deadTrees[i].x][deadTrees[i].y] += (deadTrees[i].age / 2);
	}
	deadTrees.clear(); //for������ �����ϸ� i�� �����ϴ°� �̻��ϱ⶧���� ���߿� �ϰų� i--�� �������!!
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
	cin >> k; // nxn : ���� ,m: ó������ ���� ��, k: ��� ��
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			area[i][j] = 5; //ó�� ������ ��� 5�� ������ ����
		}
	}
	int x, y, z;
	for (int i = 0; i < m; i++) {
		cin >> x;
		cin >> y;
		cin >> z;
		myTree.push_back(tree{ x,y,z });
	}

	//sort(myTree.begin(), myTree.end(), compareTree); List�� []������ ���� ������ �Ұ��ϱ⋚���� sort�Լ� ��� �Ұ���
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