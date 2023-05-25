#include "Common.h"

//�ð� ���⵵ O(NlogN)�� �ذ��� �ʿ���  ->> 50�� << 2000/sec���� �ð� ���� �ذ� ����
//Merge sort OR Quick sort OR divide and conquer
//algorithm�� vector ���̺귯���� �̿��Ͽ� quick sort�� ����������,
//�̹� ���ĵǾ� �ְų� ������ �������� ���ĵ� ��쿡�� O(N^2)�� �ð� ���⵵�� ���� �� �ִ�.

struct Student {
	vector<int> Scores;
	vector<int> Ranks;

	Student(int N) : Scores(vector<int>(N, 0)), Ranks(vector<int>(N, 1)) {};
};

bool compare(pair<int, int>& a, pair<int, int>& b) {
	if (a.second != b.second) {
		return a.second > b.second;
	}
	return a.first < b.first; //������ ���� �л��� ���� ��.
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