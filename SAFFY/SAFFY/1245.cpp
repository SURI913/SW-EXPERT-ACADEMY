#include<iostream>
#include<cmath>
#define MAX 10
using namespace std;

int N; //자성체 개수
double x[MAX], m[MAX]; //x좌표, 질량

double cal(double mid, int idx) {
	return m[idx] / pow((mid - x[idx]) ,2);
}

void BinarySearch() {
	double left, right;
	for (int i=1; i < N; i++) {
		left = x[i - 1];
		right = x[i];

		for (int cnt = 0; cnt < 100; cnt++) {
			double sum = 0, mid;

			mid = (left + right) / 2;

			for (int j = 0; j < i; j++) {
				sum += cal(mid, j);
			}
			for (int j = i; j < N; j++) {
				sum -= cal(mid, j);
			}

			if (sum == 0) break;
			//양수면 왼쪽임
			if (sum > 0) left = mid;
			else right = mid;
		}
		cout.precision(10);
		cout << " " << fixed << (left + right) / 2 << ' ';
	}
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> x[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> m[i];
		}

		cout << "#" << test_case;
		BinarySearch();
		cout << "\n";
	}

	return 0;
}