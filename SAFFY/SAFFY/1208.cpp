#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100

int main() {
	int T = 10;
	int num;
	for (int test_case = 1; test_case <= T; test_case++) {
		int dump;
		cin >> dump;
		int arr[MAX];
		for (int i = 0; i < MAX; i++) {
			cin >> arr[i];
		}

		for (int i = 0; i < dump; i++) {
			sort(arr, arr + MAX);
			arr[0]++;
			arr[MAX - 1]--;
		}
		//정렬
		sort(arr, arr + MAX); //오름차순 정렬 자동임
		cout << '#' << test_case << ' ' << arr[MAX - 1] - arr[0] << '\n';
	}

	return 0;
}