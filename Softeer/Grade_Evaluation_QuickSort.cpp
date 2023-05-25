#include "Common.h"

//시간 복잡도 O(NlogN)로 해결이 필요함  ->> 50만 << 2000/sec으로 시간 문제 해결 가능
//Merge sort OR Quick sort OR divide and conquer
//algorithm과 vector 라이브러리를 이용하여 quick sort를 진행하지만,
//이미 정렬되어 있거나 완전히 역순으로 정렬된 경우에는 O(N^2)의 시간 복잡도를 가질 수 있다ㅠㅠ
//그래도 모든 테스트 케이스 통과!

struct Student {
	vector<int> Scores;
	vector<int> Ranks;

	Student(int N) : Scores(vector<int>(N, 0)), Ranks(vector<int>(N, 1)) {};
};

bool compare(pair<int, int>& a, pair<int, int>& b) {
	if (a.second != b.second) {
		return a.second > b.second;
	}
	return a.first < b.first; //점수가 높은 학생이 먼저 옴.
}

void calculateRank(vector<int>& scores, vector<int>& ranks, int N) {
	vector<pair<int, int>> scoreWithIndex(N);
	for (int i = 0; i < N; i++) {
		scoreWithIndex[i] = { i, scores[i] };
	}
	sort(scoreWithIndex.begin(), scoreWithIndex.end(), compare);

	int rank = 1;
	for (int i = 0; i < N; i++) {
		if (i > 0 && scoreWithIndex[i].second != scoreWithIndex[i - 1].second) {
			rank = i + 1;
		}
		ranks[scoreWithIndex[i].first] = rank;
	}
}
int main()
{
	int N;
	cin >> N;
	vector<Student> Students(3, Student(N));
	vector<int> FinalScores(N, 0);
	vector<int> FinalRanks(N, 0);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Students[i].Scores[j];
		}
	}
	
	for (int i = 0; i < 3; i++) {
		calculateRank(Students[i].Scores, Students[i].Ranks, N);
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < N; j++) {
			FinalScores[j] += Students[i].Scores[j];
		}
	}

	calculateRank(FinalScores, FinalRanks, N);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < N; j++) {
			cout << Students[i].Ranks[j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < N; i++) {
		cout << FinalRanks[i] << " ";
	}

	return 0;
}
