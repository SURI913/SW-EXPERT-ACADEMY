#include<iostream>
#include<vector>
using namespace std;
int N, B, answer;
vector<int> height;
void dfs(int idx, int sum) {
	if (sum >= B) {
		//선반 높이 이상이면 갱신(최소값)
		answer = min(answer, sum);
		return;
	}

	//탐색끝 종료
	if (idx == N) return;

	//가지치기
	if (sum >= answer) return;

	//현재 직원 선택
	dfs(idx + 1, sum + height[idx]);

	// 현재 직원 선택 안함
	dfs(idx + 1, sum);
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {

		cin >> N >> B;
		for (int i = 0; i < N; i++) {
			cin >> height[i];
		}

		answer = 1e9;
		dfs(0, 0);

		cout << "#" << test_case << " " << answer - B << "\n";
	}

	return 0;
}