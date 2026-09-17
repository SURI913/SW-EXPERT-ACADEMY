#include <iostream>
#include <vector>
#include<queue>
#define MAX 1001
using namespace std;
int V, E;
vector<int> result;
vector<int> indegree;//진입차수

//위상정렬
void TopologicalSort(vector<int>* graph) {
	queue<int> q;

	for (int i = 1; i <= V; i++) {
		if (!indegree[i]) q.push(i);
	}

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		result.push_back(current); //0으로 끝난 애들만 들어가

		for (int i = 0; i < graph[current].size(); i++) {
			int next = graph[current][i];
			indegree[next]--;
			if (!indegree[next]) q.push(next); //선행작업 끝났으니 다음 방문으로 넣음
		}

	}
}


int main()
{
	int T = 10;
	for (int test_case = 1; test_case <= T; test_case++) {

		cin >> V >> E; //노드, 간선
		vector<int> graph[MAX]; //그래프 단방향
		indegree.assign(V+1, 0);
		result.clear();
		for (int i = 0; i < E; i++) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			indegree[b]++;
		}
		TopologicalSort(graph);

		cout << "#" << test_case << " ";
		for (auto& item : result) {
			cout << item << " ";
		}
		cout << endl;
	}
	return 0;
}