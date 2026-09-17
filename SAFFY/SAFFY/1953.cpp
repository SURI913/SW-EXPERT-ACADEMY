#include <iostream>
#include<queue>
#define MAX 51
using namespace std;

int arr[MAX][MAX];
int N, M, R, C, L;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1 , 0, -1, 0 };

int BFS() {
	queue<pair<int, int>>q;
	int time[MAX][MAX]{ 0, };
	bool visited[MAX][MAX] = { false, };

	q.push({ R,C });
	visited[R][C] = true;
	int result = 0;

	while (!q.empty()) {
		pair<int, int> current = q.front();
		q.pop();
		int cr = current.first;
		int cc = current.second;

		if (time[cr][cc] == L) {
			result++;
		}

		//이동할 수 있는 방향 체크. 

	}
	


	
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N >> M >> R >> C >> L;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> arr[i][j];
			}
		}
		
		int result = BFS();

		cout << "#" << test_case << " " << result << '\n';
	}
	return 0;
}