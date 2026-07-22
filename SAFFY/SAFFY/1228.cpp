#include <iostream>
#include <vector>
using namespace std;
int main() {
	int T = 1;
	for (int test_case =1; test_case <= T; test_case++) {
		int N;
		cin >> N; //암호문 길이
		vector<int> arr(N);
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		cin >> N; //명령어 개수
		for (int i = 0; i < N; i++) {
			char cmd;
			cin >> cmd; //I

			int x, y; //x의 위치에 y의 개의 숫자 삽입
			cin >> x >> y;

			vector<int> temp(y);
			for (int j = 0; j < y; j++) {
				cin >> temp[j];
			}
			//삽입
			arr.insert(arr.begin() + x, temp.begin(), temp.end());
		}
		// 출력 (앞 10개만)
		cout << "#" << test_case << " ";
		for (int i = 0; i < 10; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}