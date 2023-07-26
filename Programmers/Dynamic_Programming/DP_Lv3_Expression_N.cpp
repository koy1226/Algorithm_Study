/*
<N���� ǥ��>

���� ����
�Ʒ��� ���� 5�� ��Ģ���길���� 12�� ǥ���� �� �ֽ��ϴ�.

12 = 5 + 5 + (5 / 5) + (5 / 5)
12 = 55 / 5 + 5 / 5
12 = (55 + 5) / 5

5�� ����� Ƚ���� ���� 6,5,4 �Դϴ�. �׸��� ���� ���� ���� ���� 4�Դϴ�.
��ó�� ���� N�� number�� �־��� ��, N�� ��Ģ���길 ����ؼ� ǥ�� �� �� �ִ� ��� �� N ���Ƚ���� �ּڰ��� return �ϵ��� solution �Լ��� �ۼ��ϼ���.

���ѻ���
N�� 1 �̻� 9 �����Դϴ�.
number�� 1 �̻� 32,000 �����Դϴ�.
���Ŀ��� ��ȣ�� ��Ģ���길 �����ϸ� ������ ���꿡�� �������� �����մϴ�.
�ּڰ��� 8���� ũ�� -1�� return �մϴ�.

����� ��
N	number	return
5	12		4
2	11		3
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
��� 2)
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