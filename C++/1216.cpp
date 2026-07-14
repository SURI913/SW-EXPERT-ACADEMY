#include<iostream>
#define MAX 100
using namespace std;

bool isPalindrome(string s) {
	int left = 0;
	int right = s.length() - 1;

	while (left < right) {
		if (s[left] != s[right])
			return false;
		left++;
		right--;
	}
	//양옆 비교해서 회문인지 판별
	return true;
}

int main() {
	int T = 1;
	for (int test_case = 1; test_case <= T; test_case++) {
		int number;
		cin >> number; //문제 번호
		string board[MAX];

		for (int i = 0; i < MAX; i++) {
			cin >> board[i];
		}
		int answer = 1;
		for (int len = MAX; len > 0; len--) {
			bool found = false;

			//가로검사: 찾으면 바로 빠져나갈 수 있게 가장 긴회문만 찾으면 됨
			for (int i = 0; i < MAX && !found; i++) {
				for (int j = 0; j <= MAX-len; j++) {
					string temp = board[i].substr(j, len); //길이별로 자른 string 값으로 판별할거

					if (isPalindrome(temp)) {
						answer = len;
						found = true;
						break;
					}

				}
			}

			//세로검사
			for (int j = 0; j < MAX && !found; j++) {
				for (int i = 0; i <= MAX - len; i++) {
					string temp;
					for (int k = 0; k < len; k++) {
						temp += board[i + k][j];
					} 

					if (isPalindrome(temp)) {
						answer = len;
						found = true;
						break;
					}

				}
			}
			if (found) break;
		}
		cout << "#" << number << " " << answer << "\n";
	}
	return 0;
}