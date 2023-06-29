/*
<�� �ʰ�>

���� ����
�ſ� ���� �����ϴ� Leo�� ��� ������ ���ں� ������ K �̻����� ����� �ͽ��ϴ�. ��� ������ ���ں� ������ K �̻����� ����� ���� Leo�� ���ں� ������ ���� ���� �� ���� ������ �Ʒ��� ���� Ư���� ������� ���� ���ο� ������ ����ϴ�.

���� ������ ���ں� ���� = ���� ���� ���� ������ ���ں� ���� + (�� ��°�� ���� ���� ������ ���ں� ���� * 2)
Leo�� ��� ������ ���ں� ������ K �̻��� �� ������ �ݺ��Ͽ� �����ϴ�.
Leo�� ���� ������ ���ں� ������ ���� �迭 scoville�� ���ϴ� ���ں� ���� K�� �־��� ��, ��� ������ ���ں� ������ K �̻����� ����� ���� ����� �ϴ� �ּ� Ƚ���� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���� ����
scoville�� ���̴� 2 �̻� 1,000,000 �����Դϴ�.
K�� 0 �̻� 1,000,000,000 �����Դϴ�.
scoville�� ���Ҵ� ���� 0 �̻� 1,000,000 �����Դϴ�.
��� ������ ���ں� ������ K �̻����� ���� �� ���� ��쿡�� -1�� return �մϴ�.

����� ��
scoville	            K	return
[1, 2, 3, 9, 10, 12]	7	2
*/
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    while (pq.top() < K) {
        if (pq.size() < 2) return -1;
        int min = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();
        pq.push(min + min2 * 2);

        answer++;
    }
    return answer;
}

/*
���2) ������ �׽�Ʈ ���̽� �Ϻ� �ð� �ʰ�
����: ������ �������� sort�Լ� ȣ��� �ð��ҿ� ����.
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    while(1) {
        sort(scoville.begin(), scoville.end());
        int min = scoville.at(0);
        int min2 = scoville.at(1);
        if (min >= K) {
            return answer;
        }
        if (scoville.size() <= 1) {
            return -1;
        }
        int temp = min + 2*min2;
        scoville.erase(scoville.begin(), scoville.begin() + 2);
        scoville.insert(scoville.begin(), temp);
        answer++;
    }
    return answer;
}
*/