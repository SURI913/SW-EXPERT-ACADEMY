#include<iostream>
using namespace std;
int primes[5] = { 2, 3, 5, 7, 11 };
int primes_size = 5;

int main() {
	int T;
	int num;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		
		int count[5] = { 0 };
		cin >> num;
		//소인수분해 알고리즘
		for (int i = 0; i < primes_size; i++) {
			while (num % primes[i] == 0) {
				count[i]++;
				num /= primes[i];
			}
		}
		cout << "#" << test_case << " ";
		for (int i = 0; i < primes_size; i++) {
			cout << count[i] << ' ';
		}
		cout << "\n";
	}
	return 0;
}