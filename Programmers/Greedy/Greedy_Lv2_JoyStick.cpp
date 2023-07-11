/*
<���̽�ƽ>

���� ����
���̽�ƽ���� ���ĺ� �̸��� �ϼ��ϼ���. �� ó���� A�θ� �̷���� �ֽ��ϴ�.
ex) �ϼ��ؾ� �ϴ� �̸��� �� ���ڸ� AAA, �� ���ڸ� AAAA

���̽�ƽ�� �� �������� �����̸� �Ʒ��� �����ϴ�.

�� - ���� ���ĺ�
�� - ���� ���ĺ� (A���� �Ʒ������� �̵��ϸ� Z��)
�� - Ŀ���� �������� �̵� (ù ��° ��ġ���� �������� �̵��ϸ� ������ ���ڿ� Ŀ��)
�� - Ŀ���� ���������� �̵� (������ ��ġ���� ���������� �̵��ϸ� ù ��° ���ڿ� Ŀ��)
���� ��� �Ʒ��� ������� "JAZ"�� ���� �� �ֽ��ϴ�.

- ù ��° ��ġ���� ���̽�ƽ�� ���� 9�� �����Ͽ� J�� �ϼ��մϴ�.
- ���̽�ƽ�� �������� 1�� �����Ͽ� Ŀ���� ������ ���� ��ġ�� �̵���ŵ�ϴ�.
- ������ ��ġ���� ���̽�ƽ�� �Ʒ��� 1�� �����Ͽ� Z�� �ϼ��մϴ�.
���� 11�� �̵����� "JAZ"�� ���� �� �ְ�, �̶��� �ּ� �̵��Դϴ�.
������� �ϴ� �̸� name�� �Ű������� �־��� ��, �̸��� ���� ���̽�ƽ ���� Ƚ���� �ּڰ��� return �ϵ��� solution �Լ��� ���弼��.

���� ����
name�� ���ĺ� �빮�ڷθ� �̷���� �ֽ��ϴ�.
name�� ���̴� 1 �̻� 20 �����Դϴ�.

����� ��
name	        return
"JEROEN"	    56
"JAN"	        23
"CANAAAAANAN"   48
*/
//���1)
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int length = name.length();
    int move = length - 1; // Ŀ���� ���������θ� �̵��ϴ� ��츦 �⺻���� ����

    for (int i = 0; i < length; i++) {
        int up_down = min(name[i] - 'A', 'Z' - name[i] + 1); // ��, �Ʒ� �߿��� �� ����� ���� ã��
        answer += up_down;

        int next = i + 1;
        while (next < length && name[next] == 'A') // �������� �����ؾ� �� ���ĺ� ��ġ�� ã��
            next++;

        move = min(move, i + length - next + min(i, length - next)); // ���� ��ġ�� �������� ����, ������ �߿��� �� ����� ���� ã��
    }

    answer += move;
    return answer;
}

/*
���2)
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int LUT[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1 };

int solution(string name) {
    int answer = 0;
    for (auto ch : name)
        answer += LUT[ch - 'A'];
    int len = name.length();
    int left_right = len - 1;
    for (int i = 0; i < len; ++i) {
        int next_i = i + 1;
        while (next_i < len && name[next_i] == 'A')
            next_i++;
        left_right = min(left_right, i + len - next_i + min(i, len - next_i));
    }
    answer += left_right;
    return answer;
}
*/