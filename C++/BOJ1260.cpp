#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

void print(vector<int> result) {
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << "\n";
}

void dfs(vector<vector<int>> vec, int startNode) {
	vector<int> result;
	vector<bool> isVisited(vec.size());
	
	stack<int> stack;
	stack.push(startNode);
	isVisited[startNode] = true;
	result.push_back(startNode);

	while (!stack.empty()){
		int currentNode = stack.top();
		bool flag = false;

		for (int i = 0; i < vec[currentNode].size(); i++) {
			int nextNode = vec[currentNode][i];
			if (!isVisited[nextNode]) {
				stack.push(nextNode);
				isVisited[nextNode] = true;
				result.push_back(nextNode);
				flag = true;
				break;
			}

		}
		if (!flag) stack.pop();
	}
	print(result);
	return;
}

void bfs(vector<vector<int>> vec, int startNode) {
	queue<int> q;
	q.push(startNode);

	vector<bool> isVisited(vec.size());
	isVisited[startNode] = true;

	vector<int> result;

	while (!q.empty()) {
		int currentNode = q.front();
		result.push_back(currentNode);
		q.pop();

		for (int i = 0; i < vec[currentNode].size(); i++) {
			if (!isVisited[vec[currentNode][i]]) {
				q.push(vec[currentNode][i]);
				isVisited[vec[currentNode][i]] = true;
			}
		}
	}
	print(result);
	return;
}

int main() {
	int n, m, start;
	cin >> n >> m >> start;
	
	vector<vector<int>> graph(n + 1);// 입력을 node 1,2... 이런 방식이므로 +1반드시 해야함
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(graph, start);
	bfs(graph, start);
	return 0;
}