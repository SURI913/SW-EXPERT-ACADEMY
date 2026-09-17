#include<iostream>
#include<algorithm>
#define MAX 251
using namespace std;

string addBigIntger(string a, string b) {
	string result = "";

	int i = a.size() - 1;
	int j = b.size() - 1;
	int carry = 0;

	//아니면 벡터로 해야함
	while (i >= 0 || j >= 0 || carry)
	{
		int sum = carry;

		if (i >= 0)
		{
			sum += a[i] - '0';
			i--;
		}

		if (j >= 0)
		{
			sum += b[j] - '0';
			j--;
		}

		result += (sum % 10) + '0'; //연산과 동시에 문자열로 더하기
		carry = sum / 10;
	}
	reverse(result.begin(), result.end());

	return result;
}

int main() {
	string dp[MAX];

	dp[1] = "1";
	dp[2] = "3";

	for (int i = 3; i < MAX; i++) {
		//dp[i-2]*2
		string tmp = addBigIntger(dp[i - 2], dp[i - 2]);
		dp[i] = addBigIntger(dp[i - 1], tmp);
	}

	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int N;
		cin >> N;

		cout << '#' << test_case << ' ' << dp[N] << endl;
	}

	return 0;
}