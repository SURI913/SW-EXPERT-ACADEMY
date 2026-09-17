#include<iostream>
#include<vector>
#include <tuple>
#include <algorithm>
using namespace std;
#define MAX_V 100001

int parent[MAX_V]; //사이클 체크용

void SetParent(int n) {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
}

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	int rootA = Find(a);
	int rootB = Find(b);

	if (rootA != rootB) {
		//a-b
		parent[rootB] = rootA;
	}
}

bool Compare(tuple<int, int, int>& a, tuple<int, int, int>& b) {
	return get<2>(a) < get<2>(b);
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int V, E;
		cin >> V >> E;
		SetParent(V);
		vector<tuple<int, int, int>> graph;
		for (int i = 0; i < E; i++) {
			int A, B, C;
			cin >> A >> B >> C;
			graph.push_back({A, B,C}); //A시작노드, B도착노드, C가중치
		}
		//C를 기준으로 오름차순 정렬
		std::sort(graph.begin(), graph.end(), Compare); // 오름차순 정렬

		long long MST = 0; //가중치 합 고려 int 벗어날 수 있음 1,000,000*100,000라
		int resultE = V - 1;
		for (int i = 0; i < E; i++) {
			if (resultE == 0) break; //V-1개의 간선을 선택했다면 종료

			int A = get<0>(graph[i]);
			int B = get<1>(graph[i]);
			int C = get<2>(graph[i]);


			if (Find(A) != Find(B)) {
				//0이 시작위치 1이 끝위치, 2가중치
				Union(A,B);
				MST += C;
				resultE--;
			}
		}

		cout << "#" << test_case << " " << MST << endl;

	}
	return 0;
}