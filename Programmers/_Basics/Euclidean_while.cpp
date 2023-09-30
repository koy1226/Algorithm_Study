#include <string>
#include <vector>

using namespace std;
// 공약수 찾기
int GCD(int num, int den)
{
    while (den != 0)
    {
        int remainder = num % den;
        num = den;
        den = remainder;
    }
    return num;
}

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    int denom = denom1 * denom2;
    int num1 = numer1 * denom2;
    int num2 = numer2 * denom1;
    int numer = num1 + num2;
    int gcd = GCD(numer, denom); // 함수 호출

    numer /= gcd;
    denom /= gcd;

    answer.push_back(numer);
    answer.push_back(denom);

    return answer;
}