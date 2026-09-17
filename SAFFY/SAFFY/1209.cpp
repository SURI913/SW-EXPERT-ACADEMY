#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100
int arr[MAX][MAX];

int main() {
	int T = 10, testNum;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> testNum;

		int rowSum = 0, colSum = 0, diaSum[2] = { 0, }; //가로, 세로, 대각
		int rowMax = 0, colMax = 0, diaMax = 0; //가로, 세로, 대각
		//입력
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < MAX; i++) {
			rowSum = 0;
			colSum = 0;
			for (int j = 0; j < MAX; j++) {
				rowSum += arr[i][j];
				colSum += arr[j][i];
			}
			diaSum[0] += arr[i][i]; 
			diaSum[1] += arr[i][(MAX - 1) - i]; 

			rowMax = max(rowSum, rowMax);
			colMax = max(colSum, colMax);
		}
		diaMax = max(diaSum[0], diaSum[1]);

		int result = max({ diaMax, colMax, rowMax });

		cout << '#' << testNum << ' ' << result << '\n';
	}

	return 0;
}