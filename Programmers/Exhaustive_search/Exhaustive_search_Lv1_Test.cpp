/*
<���ǰ��>

���� ����
�����ڴ� ������ ������ ����� �ظ��Դϴ�. ������ ���ι��� ���ǰ�翡 ���� ������ ���� ������ �մϴ�. �����ڴ� 1�� �������� ������ �������� ������ ���� ����ϴ�.

1�� �����ڰ� ��� ���: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
2�� �����ڰ� ��� ���: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
3�� �����ڰ� ��� ���: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...

1�� �������� ������ ���������� ������ ������� ���� �迭 answers�� �־����� ��, ���� ���� ������ ���� ����� �������� �迭�� ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���� ����
������ �ִ� 10,000 ������ �����Ǿ��ֽ��ϴ�.
������ ������ 1, 2, 3, 4, 5�� �ϳ��Դϴ�.
���� ���� ������ ���� ����� ������ ���, return�ϴ� ���� �������� �������ּ���.

����� ��
answers		return
[1,2,3,4,5]	[1]
[1,3,2,4,2]	[1,2,3]
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> student1 = { 1, 2, 3, 4, 5 };
    vector<int> student2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> student3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    vector<int> scores(3);

    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == student1[i % student1.size()]) scores[0]++;
        if (answers[i] == student2[i % student2.size()]) scores[1]++;
        if (answers[i] == student3[i % student3.size()]) scores[2]++;
    }

    int maxScore = *max_element(scores.begin(), scores.end());
    for (int i = 0; i < 3; i++) {
        if (scores[i] == maxScore) answer.push_back(i + 1);
    }

    return answer;
}
