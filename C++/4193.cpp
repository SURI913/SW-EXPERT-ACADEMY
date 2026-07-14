#include <iostream>
#include <queue>
using namespace std;
#define MAX 16
int N;
int map[MAX][MAX];
bool visited[MAX][MAX][3];

//방향접근용
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

struct Node {
	int x;
	int y;
	int time;
};

int bfs(int startX, int startY, int endX, int endY) {
	queue<Node> q;
	memset(visited, false, sizeof(visited)); //배열 초기화 기억안나면 그냥 코드 짤 것

	q.push({ startX, startY, 0 });
	visited[startX][startY][0];

	while (!q.empty()) {
		Node current = q.front(); //bfs는 q안에 보관한걸 꺼내서 체크하는게 메인 dfs는 재귀
		q.pop();

		//도착 시 시간 반환
		if (current.x == endX && current.y == endY) return current.time;

		//방향 체크
		for (int direction = 0; direction < 4; direction++) {
			int nx = current.x + dx[direction];
			int ny = current.y + dy[direction];
			int nt = current.time + 1; //조건: 이동마다 1초

			//범위에서 벗어남
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			//조건: 장애물 있음 이동 불가
			if (map[nx][ny] == 1) continue;

			//조건: 소용돌이 2초동안 이동 불가 이후 이동
			if (map[nx][ny] == 2) {
				if (nt % 3 != 2) {
					//0-X,1-X,2-O 주기 반복. 주기는 % 연산

					//대기
					if (!visited[current.x][current.y][nt % 3]) {
						//조건: 이미 방문한 지점은 그냥 넘길 수 있다
						visited[current.x][current.y][nt % 3] = true;
						q.push({ current.x,current.y,nt });
					}
					continue;
				}
			}
			if (!visited[nx][ny][nt % 3]) {
				visited[nx][ny][nt % 3] = true;
				q.push({ nx, ny, nt });
			}
		}
	}
	return -1;
}
int main()
{
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		int startX, startY, endX, endY;
		cin >> startX >> startY >> endX >> endY;

		int answer = bfs(startX, startY, endX, endY);

		cout << "#" << test_case << " " << answer << endl;
	}
	
	return 0;
}