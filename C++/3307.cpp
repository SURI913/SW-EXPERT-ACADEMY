#include <iostream>
#define MAX 1001
using namespace std;
int arr[MAX];
int dp[MAX];
int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int N;
		for (int i = 0; i < N; i ++ ) {
			cin >> arr[i];
		}
		int answer = 0;

		for (int i = 0; i < N; i + ) {
			dp[i] = 1;

			for (int j = 0; j < i; j++) {
				// 이전 값이 더 작으면 증가 수열 가능
				if (arr[j] < arr[i]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			answer = max(answer, dp[i]);
		}
		cout << "#" << test_case << " " << answer << '\n';
	}
	return 0;
}