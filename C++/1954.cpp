#include <iostream>
using namespace std;
#define MAX 10

int dc[] = { 0,1,0,-1 };
int dr[] = { 1,0,-1,0 };
int N, T;
int arr[MAX][MAX];

void ClearArray(int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr[i][j] = 0;
		}
	}
}

void PrintArray(int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {

	//입력
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		ClearArray(N);
		int nc, nr, dir = 0;  // 0: →, 1 : ↓, 2 : ←, 3 : ↑
		int count = 0, col = 0, row = 0;
		int check = N * N;
		while (check--) {
			arr[col][row] = ++count;

			//다음으로 갈 위치
			nc = col + dc[dir]; 
			nr = row + dr[dir];

			//다음 값이 0 아니거나 || 인덱스가 N을 넘어서면 방향 바꿈
			if (arr[nc][nr] != 0 || nc >= N || nr >= N || nr < 0 || nc < 0) {
				dir = (dir + 1) % 4;
				nc = col + dc[dir];
				nr = row + dr[dir];
			}
			col = nc;
			row = nr;
		}

		//출력
		PrintArray(N);
	}
	return 0;
}