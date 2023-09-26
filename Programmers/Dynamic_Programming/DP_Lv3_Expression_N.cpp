/*
<N으로 표현>

문제 설명
아래와 같이 5와 사칙연산만으로 12를 표현할 수 있습니다.

12 = 5 + 5 + (5 / 5) + (5 / 5)
12 = 55 / 5 + 5 / 5
12 = (55 + 5) / 5

5를 사용한 횟수는 각각 6,5,4 입니다. 그리고 이중 가장 작은 경우는 4입니다.
이처럼 숫자 N과 number가 주어질 때, N과 사칙연산만 사용해서 표현 할 수 있는 방법 중 N 사용횟수의 최솟값을 return 하도록 solution 함수를 작성하세요.

제한사항
N은 1 이상 9 이하입니다.
number는 1 이상 32,000 이하입니다.
수식에는 괄호와 사칙연산만 가능하며 나누기 연산에서 나머지는 무시합니다.
최솟값이 8보다 크면 -1을 return 합니다.

입출력 예
N	number	return
5	12	4
2	11	3
*/

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int solution(int N, int number) {
    const int INF = 987654321;
    std::vector<std::vector<int>> DP(9, std::vector<int>());

    for (int i = 1; i <= 8; ++i) {
        DP[i].push_back(std::stoi(std::string(i, static_cast<char>('0' + N))));
        if (DP[i].back() == number) return i;
    }

    for (int i = 2; i <= 8; ++i) {
        for (int j = 1; j < i; ++j) {
            for (int n1 : DP[j]) {
                for (int n2 : DP[i - j]) {
                    DP[i].push_back(n1 + n2);
                    DP[i].push_back(n1 - n2);
                    DP[i].push_back(n1 * n2);
                    if (n2 != 0) DP[i].push_back(n1 / n2);
                }
            }
        }
        DP[i].erase(std::unique(DP[i].begin(), DP[i].end()), DP[i].end()); // �ߺ� ����
        if (std::find(DP[i].begin(), DP[i].end(), number) != DP[i].end()) return i;
    }

    return -1;
}

/*
Case 2)
#include <string>
#include <vector>

using namespace std;

int minCnt = 9;

void dp(int N, int number, int cnt, int now){
    if(cnt > 8){
        return;
    }

    if(now == number){
        minCnt = min(minCnt, cnt);
    }

    int operand = 0;

    for(int i=1; i<=9; i++){
        //5, 55, 555 �����
        operand = operand*10 + N;

        dp(N, number, cnt + i, now + operand);
        dp(N, number, cnt + i, now - operand);

        if(now != 0){
            dp(N, number, cnt + i, now * operand);
            dp(N, number, cnt + i, now / operand);
        }
    }


}
int solution(int N, int number) {
    int answer = 0;
    dp(N, number, 0, 0);
    answer = ((minCnt > 8) ? -1 : minCnt);
    return answer;
}
*/