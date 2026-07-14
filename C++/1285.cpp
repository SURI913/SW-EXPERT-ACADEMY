#include<iostream>
using namespace std;

int main() {
	int T, N, t_pos; //테스트케이스, 돌을 던질 사람의 수
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;

		int minDist = 200000;
		int count = 0;

		while (N--) {
			cin >> t_pos;

			int dist = abs(t_pos);

			if (dist < minDist) {
				count = 1;
				minDist = dist;
			}
			else if (dist == minDist) {
				count++;
			}
		}
		cout << "#" << i << " " << minDist << " " << count << "\n";
	}
	return 0;
}