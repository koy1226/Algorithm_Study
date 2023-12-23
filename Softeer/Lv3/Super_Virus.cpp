#include<iostream>

using namespace std;

const int mod = 1000000007;
long long DivideConquer(long long P, long long N) {
  if (N == 0) return 1;
  if (N == 1) return P;

  long long half = DivideConquer(P, N/2);
  long long result = (half * half) % mod;
  if (N % 2 == 1) result = (result * P) % mod;

  return result;
}

int main(int argc, char** argv)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long K, P, N;
  cin >> K >> P >> N;

  long long final_virus = (K * DivideConquer(P, 10 * N)) % mod;
  
  cout << final_virus;
  
   return 0;
}