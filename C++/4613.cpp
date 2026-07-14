#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int N,M;
		cin >> N >> M;
		vector<string> flag(N);

		for (int i = 0; i < N; i++) {
			cin >> flag[i];
		}
		int answer = 987654321;
		// w : 흰색 구역의 마지막 행
		for (int w = 0; w < N-2; w ++ ) {
			// b : 파란색 구역의 마지막 행
			for (int b = w+1; b < N-1; b++) {
				int cnt = 0;

				// W 구역
				for (int i = 0; i <= w; i++) {
					for (int j = 0; j < M; j++) {
						// W가 아니면 바꿔야 함
						if (flag[i][j] != 'W')
						{
							cnt++;
						}
					}
				}

				//B 구역
				for (int i = w+1; i <= b; i++) {
					for (int j = 0; j < M; j++) {
						// B가 아니면 바꿔야 함
						if (flag[i][j] != 'B')
						{
							cnt++;
						}
					}
				}

				//R 구역
				for (int i = b+1; i < N; i++) {
					for (int j = 0; j < M; j++) {
						// R가 아니면 바꿔야 함
						if (flag[i][j] != 'R')
						{
							cnt++;
						}
					}
				}
				answer = min(answer, cnt);
			}
		}
		cout << "#" << test_case << " " << answer << '\n';
	}
	return 0;
}