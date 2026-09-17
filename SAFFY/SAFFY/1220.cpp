#include<iostream>
#define MAX 100
using namespace std;

int main() {
	int T = 10;
	for (int test_case = 1; test_case <= T; test_case++) {
		int N;
		cin >> N; //문제 번호
		int arr[MAX][MAX];

		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				cin >> arr[i][j];
				//입력
			}
		}

		int result = 0;
		//세로만 검사. 위에 반은 1 아래 반은 2 -> 인접교차 고려 그냥 인덱스값 기억하자 
		for (int c = 0; c < MAX; c++) {
			int current = 0;
			for (int r = 0; r < MAX; r++) {
				if (arr[r][c] == 1)current = arr[r][c];
				else if (arr[r][c] == 2 && current == 1) {
					result++;
					current = arr[r][c];
				}
			}
		}
		cout << "#" << test_case << " " << result << "\n";
	}
	return 0;
}