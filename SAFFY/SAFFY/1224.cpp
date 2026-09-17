#include<iostream>
#include<stack>

#define MAX 100
using namespace std;

enum Operator
{
	OPENING=40, //아스키40이 괄호~ 43까지 +
	CLOSING,
	TIMES,
	PLUS,
};

string MakePostfix(string infix) {
	stack<char> op;
	string postfix ="";

	for (auto& c : infix) {

		// 숫자면 바로 담음
		if ('0' <= c && c <= '9') {
			postfix += c;
		}
		else if (c == '(') op.push(c);
		else if (c == ')') {
			//op에 넣은 '(' 나올때까지 pop
			while (!op.empty() && op.top() != '(') {
				postfix += op.top();
				op.pop();
			}
			op.pop();
		}
		else if (c == '+' || c == '*') {

			while (!op.empty() &&
				op.top() != '(' &&
				op.top() <= c) {
				//아스키로 봤을때 수가 작을 수록 우선순위
				postfix += op.top();
				op.pop();
			}

			op.push(c);
		}
	}

	while (!op.empty()) {
		postfix += op.top();
		op.pop();
	}

	return postfix;
}


int Calculate(string postfix) {
	stack<int> num;
	int result =0;

	for (auto& c : postfix) {
		if (c == '*' || c == '+') {
			//순서 중요
			int right = num.top();
			num.pop();

			int left = num.top();
			num.pop();

			if (c == '+') {
				result = left + right;
			}
			else if (c == '*') {
				result = left * right;
			}

			num.push(result);
		}
		else num.push(c - '0');//숫자로 변환
	}

	return result;
}

int main() {
	int T = 10;
	for (int test_case = 1; test_case <= T; test_case++) {
		int len;
		string infix;
		cin >> len >> infix;

		string postfix = MakePostfix(infix);
		int result = Calculate(postfix);

		cout << "#" << test_case << " " << result << "\n";
	}
	return 0;
}