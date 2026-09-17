#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 1001
using namespace std;

string arr[MAX];

int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1, 0, -1, 0 };

int N, M;

int dist[MAX][MAX] = { -1, }; //방문X 대용

bool IsRange(int r, int c) {
	return (r >= 0 && r < N && c >= 0 && c < M);
}

int BFS() {
	queue<pair<int, int>> q;
	int result = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dist[i][j] = -1;
			if (arr[i][j] == 'W') {
				q.push({ i,j });
				dist[i][j] = 0; //여기서 초기화 그러면 계산시 지장 X
			}
		}
	}

	while (!q.empty())
	{
		pair<int,int> current = q.front();
		q.pop();
		int cr = current.first;
		int cc = current.second;

		if (arr[cr][cc] == 'L') {
			//물에 도달
			result += dist[cr][cc];
		}

		for (int i = 0; i < 4; i++) {
			int nr = cr + dr[i];
			int nc = cc + dc[i];

			if (IsRange(nr, nc) && dist[nr][nc] == -1) {
				dist[nr][nc] = dist[cr][cc] + 1;
				q.push({ nr,nc });
			}
		}
	}

	return result;
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {

		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		int result = BFS();
		cout << '#' << test_case << " " << result << endl;
	}
	return 0;
}