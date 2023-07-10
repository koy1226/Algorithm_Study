/*
<ü����>

���� ����
���ɽð��� ������ ���, �Ϻ� �л��� ü������ �������߽��ϴ�. ������ ���� ü������ �ִ� �л��� �̵鿡�� ü������ �����ַ� �մϴ�. �л����� ��ȣ�� ü�� ������ �Ű��� �־�, �ٷ� �չ�ȣ�� �л��̳� �ٷ� �޹�ȣ�� �л����Ը� ü������ ������ �� �ֽ��ϴ�. ���� ���, 4�� �л��� 3�� �л��̳� 5�� �л����Ը� ü������ ������ �� �ֽ��ϴ�. ü������ ������ ������ ���� �� ���� ������ ü������ ������ ���� �ִ��� ���� �л��� ü�������� ���� �մϴ�.

��ü �л��� �� n, ü������ �������� �л����� ��ȣ�� ��� �迭 lost, ������ ü������ ������ �л����� ��ȣ�� ��� �迭 reserve�� �Ű������� �־��� ��, ü�������� ���� �� �ִ� �л��� �ִ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
��ü �л��� ���� 2�� �̻� 30�� �����Դϴ�.
ü������ �������� �л��� ���� 1�� �̻� n�� �����̰� �ߺ��Ǵ� ��ȣ�� �����ϴ�.
������ ü������ ������ �л��� ���� 1�� �̻� n�� �����̰� �ߺ��Ǵ� ��ȣ�� �����ϴ�.
���� ü������ �ִ� �л��� �ٸ� �л����� ü������ ������ �� �ֽ��ϴ�.
���� ü������ ������ �л��� ü������ ���������� �� �ֽ��ϴ�. �̶� �� �л��� ü������ �ϳ��� �������ߴٰ� �����ϸ�, ���� ü������ �ϳ��̱⿡ �ٸ� �л����Դ� ü������ ������ �� �����ϴ�.

����� ��
n	lost	reserve	    return
5	[2, 4]	[1, 3, 5]	5
5	[2, 4]	[3]	        4
3	[3]	    [1]	        2
*/ 
//������ ü������ ������ �л��� ü������ ���� ������ ���� ���.
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student(n, 1);

    for (int i = 0; i < lost.size(); i++)
        student[lost[i] - 1]--;

    for (int i = 0; i < reserve.size(); i++)
        student[reserve[i] - 1]++;

    for (int i = 0; i < student.size(); i++) {
        if (student[i] > 1) {
            if (i > 0 && student[i - 1] == 0) {
                student[i]--;
                student[i - 1]++;
            }
            else if (i < student.size() - 1 && student[i + 1] == 0) {
                student[i]--;
                student[i + 1]++;
            }
        }
    }

    for (int i = 0; i < student.size(); i++)
        if (student[i] > 0) answer++;

    return answer;
}

/*
Fail case
40.0 / 100

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<bool> check(n, false);

    for (int i = 0; i < reserve.size(); i++) {
        check[reserve[i]-1] = true;
        answer++;
    }
    for (int i = 0; i < n; i++) {
        if (check[i] == false) {
            if (i != n - 1 && check[i+1] == true) {
                check[i] = true;
                answer++;
            }
            else if (i != 0 && check[i-1] == true) {
                check[i] = true;
                answer++;
            }
        }
    }

    return answer;
}

Fail case 2
83.3 / 100

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> student(n, 1);

    for (int i = 0; i < lost.size(); i++)
        student[lost[i] - 1]--;

    for (int i = 0; i < reserve.size(); i++)
        student[reserve[i] - 1]++;

    for (int i = 0; i < student.size(); i++) {
        if (student[i] == 0) {
            if (i != student.size() - 1 && student[i + 1] == 2) {
                student[i + 1]--;
                student[i]++;
            }
            else if (i != 0 && student[i - 1] == 2) {
                student[i - 1]--;
                student[i]++;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < student.size(); i++)
        if (student[i] != 0) answer++;

    return answer;
}

*/