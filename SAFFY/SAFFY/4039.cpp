#include<iostream>
#include<unordered_set>
using namespace std;
unordered_set<char> hashTable;

//슬라이딩 윈도우 + 해시함수
int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int L;
		string S;
		cin >> L >> S;
		hashTable.clear();

		

		int maxLen = L/2; //2번이상 반복해서 나오는 가장 긴 중복 문자열이니까 일단 반토막내
		hashTable.
		for (int i = maxLen; i < S.size(); i++) {

		}


		cout << "#" << test_case << " " << "\n";
	}

	return 0;
}