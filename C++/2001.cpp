#include<iostream>
using namespace std;
#define MAX 16
int arr[MAX][MAX];
int dp[MAX][MAX];

int main() {
	int T;
	int num;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int N, M, sum, maxVal = 0;
		cin >> N >> M;
		for (int i = 1; i <= N; i++) { //buttom-up 점화식이라서 0부터 시작이 아닌 1부터 시작
			for (int j = 1; j <= N; j++) {
				cin >> arr[i][j];
			}
		}
		
		//누적합 = 나+위+왼 - 윗 대각
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dp[i][j] = arr[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
			}
		}
		
		//M*M 영역
		
		for (int i = M; i <= N; i++) {
			for (int j = M; j <= N; j++) {
				sum = dp[i][j] - dp[i - M][j] - dp[i][j - M] + dp[i - M][j - M];
				maxVal = max(sum, maxVal);
			}
		}
		cout << '#' << test_case << ' ' << maxVal << '\n';
	}
	return 0;
}