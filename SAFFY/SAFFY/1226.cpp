#include <iostream>
#include<cstring>
#include<string>
#define MAX 16
using namespace std;
string arr[MAX];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

bool result, visited[MAX][MAX];

void DFS(int cx, int cy) {

	//진입
	visited[cy][cx] = true;

	if (arr[cy][cx] == '3') {
		//도착
		result = true;
		return; 
	}

	for (int j = 0; j < 4; j++) {
		int nx = cx + dx[j];
		int ny = cy + dy[j];

		//범위제한이 있어야 했음
		if (nx < 0 || ny < 0 || nx >= MAX || ny >= MAX) continue;
		if (arr[ny][nx] == '1') continue;
		if (visited[ny][nx]) continue;
		DFS(nx, ny); //이동

		if (result) return;
	}
}

int main()
{
	int T = 10;
	for (int test_case = 1; test_case <= T; test_case++) {

		int tc;
		cin >> tc;

		memset(visited, false, sizeof(visited));
		result = false;

		for (int i = 0; i < MAX; i++) {
			cin >> arr[i];
		}
		DFS(1, 1);

		cout << "#" << tc << " " << (int)result << endl;
	}

}