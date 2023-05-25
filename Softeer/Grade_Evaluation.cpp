#include "Common.h"
//시간 복잡도 O(N^2) 3 ≤ N ≤ 100,000  ->>  C++기준 2000만/sec << 100억으로 시간 초과 발생한다.
//게다가 3중 for문 부분도 있어 더 걸릴 것이다..
//실제 반은 맞고 반은 시간초과.

int main()
{
	int N;
	cin >> N;
	int** Grades = new int* [3]; //rows
	for (int i = 0; i < 3; i++) { //cols
		Grades[i] = new int[N];
		for (int j = 0; j < N; j++)
			cin >> Grades[i][j];
	}

	int** Rank = new int* [4];
	int* Grade_sum = new int[N];
	for (int i = 0; i < 4; i++) {
		Rank[i] = new int[N];
		for (int j = 0; j < N; j++) {
			Rank[i][j] = 1;
			Grade_sum[j] = 0;
		}
	}
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (Grades[i][j] < Grades[i][k])
					Rank[i][j]++;
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < N; j++) {
			Grade_sum[j] += Grades[i][j];
		}
	}

	for (int j = 0; j < N; j++) { 
		for (int k = 0; k < N; k++) {
			if (Grade_sum[j] < Grade_sum[k])
				Rank[3][j]++;
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < N; j++) {
			cout << Rank[i][j] << " ";
		}
		cout << endl;
	}

	delete[] Grade_sum;

	for (int i = 0; i < 4; ++i)
		delete[] Rank[i];
	delete[] Rank;

	for (int i = 0; i < 3; ++i)
		delete[] Grades[i];
	delete[] Grades;

	return 0;
}
