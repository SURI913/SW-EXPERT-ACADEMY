#include<iostream>
#include<algorithm>
#define COST_MAX 4
#define PLAN_MAX 12
using namespace std;

int N, answer;
int cost[COST_MAX]; //일일비용 1일 , 1달, 3달, 1년 순
int plan[PLAN_MAX]; //달에 몇번 갈건지
int minPlan[PLAN_MAX]; 

void dfs(int index, int price) {

	//탐색이 끝났음
	if (index >= PLAN_MAX) {
		answer = min(answer, price);
		return;
	}

	// 가지치기
	if (price >= answer) {
		return;
	}
	
	if (index <= PLAN_MAX - 2) {
		// 2달 남으면 => 3달 결제X
		dfs(index + 3, price + cost[2]);
	}

	dfs(index + 1, price + minPlan[index]); //한달치 or 일일권 끊기
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {

		for (int i = 0; i < COST_MAX; i++) {
			cin >> cost[i];
		}
		for (int i = 0; i < PLAN_MAX; i++) {
			cin >> plan[i];
		}
		for (int i = 0; i < PLAN_MAX; i++) {
			minPlan[i] = min(cost[0] * plan[i], cost[1]); //일일권 vs 1달권 비교해서 최소금액 측정.
		}

		answer = cost[3]; //
		dfs(0, 0);

		cout << "#" << test_case << " " << answer<< "\n";
	}

	return 0;
}