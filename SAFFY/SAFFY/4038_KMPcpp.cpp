#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> MakePi(string S) {
	
	vector<int> pi;
	int sSize = S.size();
	pi.assign(sSize, 0);
	int j = 0;
	for (int i = 1; i < sSize; i++) { 
		
		while (j > 0 && S[i] != S[j]) {
			j = pi[j - 1];
		}
		if (S[i] == S[j]) {
			j++;
			pi[i] = j;
		}

	}
 	return pi;
}

//KMP
int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {

		string S;
		cin >> S;
		vector<int> pi = MakePi(S);
		//S^N => 무조건 반복일테니 마지막 열에 있는게 젤 김
		//근데 얼만큼 반복인지 보려면 결국 작은 접미사or접두사를 알아야 함
		//pi는 가장 긴 반복된 접두사와 접미사 길이를 알려줌
		//전체길이 - 가장긴 접미사길이를 하면 = 접미사 시작점을 알수있음 그게 젤 짧은 접미사
		
		int sSize = S.size();
		int result = sSize - pi[sSize - 1];
		//가장짧은 접미사를 가지고
		// 전체길이 / 접미사 = n을 알수있지
		
		result = sSize / result;
		

		cout << '#' << test_case << ' ' << result << endl;
	}
	return 0;
}