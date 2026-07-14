#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int N, K, input; //수강한 사람, 제출한 사람
		bool arr[MAX] = {false,};
		cin >> N >> K;
		for (int i = 0; i < K; i++) {
			cin >> input;
			arr[input] = true;
		}

		cout << "#" << test_case << " ";
		for (int i = 1; i <= N; i++) {
			if (!arr[i]) {
				cout << i << ' ';
			}
		}
		cout << "\n";
	}
	return 0;
}