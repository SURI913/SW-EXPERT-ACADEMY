#include<iostream>
using namespace std;
#define MAX 11
int arr[MAX][MAX];

int main() {
	int T;
	int num;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) { //값을 넣을때 부터 피라미드 모양으로 맨 1열이 0이어야하니까 1인 부분은 그 부분
			for (int j = 0; j <= i; j++) {
				if (j == 0 || j == i)
					arr[i][j] = 1;
				else
					arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
		}
		//출력
		cout << '#' << test_case << '\n';
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= i; j++) {
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}