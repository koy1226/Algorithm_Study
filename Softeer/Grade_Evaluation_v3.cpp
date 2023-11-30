/*
Link : https://softeer.ai/practice/6294
*/
// when i resolved Prefix Sum
#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

int main(int argc, char** argv)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, K;
  cin >> N >> K;

  vector<int> scores(N);
  vector<long long> prefixSum(N, 0);
  
  for (int i = 0; i < N; i++) {
    cin >> scores[i];
    if (i == 0) {
      prefixSum[i] = scores[i];
    } else {
      prefixSum[i] = prefixSum[i - 1] + scores[i];
    }
  }

  for (int i = 0; i < K; i++) {
    int A, B;
    cin >> A >> B;

    long long sum = prefixSum[B - 1];
    if(A > 1) {
      sum -= prefixSum[A - 2];
    }

    double avg = static_cast<double>(sum) / (B - A + 1);
    cout << fixed << setprecision(2) << avg << endl;
    
  }

  return 0;
}