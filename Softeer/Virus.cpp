#include<iostream>
#define MOD 1000000007

using namespace std;

int main()
{
	long long K, P, N;
	cin >> K >> P >> N;
	long long result = K;

	for (int i = 0; i < N; i++) {
		result = (result * P) % MOD;
	}

	cout << result;

	return 0;
}