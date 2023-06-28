/*
<�ùٸ� ��ȣ>

���� ����
��ȣ�� �ٸ��� ¦�������ٴ� ���� '(' ���ڷ� �������� �ݵ�� ¦��� ')' ���ڷ� ������ �Ѵٴ� ���Դϴ�. ���� ���

"()()" �Ǵ� "(())()" �� �ùٸ� ��ȣ�Դϴ�.
")()(" �Ǵ� "(()(" �� �ùٸ��� ���� ��ȣ�Դϴ�.
'(' �Ǵ� ')' �θ� �̷���� ���ڿ� s�� �־����� ��, ���ڿ� s�� �ùٸ� ��ȣ�̸� true�� return �ϰ�, �ùٸ��� ���� ��ȣ�̸� false�� return �ϴ� solution �Լ��� �ϼ��� �ּ���.

���ѻ���
���ڿ� s�� ���� : 100,000 ������ �ڿ���
���ڿ� s�� '(' �Ǵ� ')' �θ� �̷���� �ֽ��ϴ�.

����� ��
s	        answer
"()()"	    true
"(())()"	true
")()("	    false
"(()("	    false
*/
#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> bracket;

    for (char c : s) {
        if (c == '(') {
            bracket.push(c);
        }
        else {
            if (bracket.empty()) {
                return false;
            }
            else {
                bracket.pop();
            }
        }
    }
    return bracket.empty();
}
/*
���2)
#include <string>

using namespace std;

bool solution(string s)
{
    int cnt = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            cnt++;
        } else {
            if (cnt == 0) //���� ��ȣ ���� ���� ��ȣ�� ���Դµ�, cnt�� 0�϶� false
                return false;
            cnt--;
        }
    }
    if (cnt != 0)
        return false;

    return cnt == 0;
}
*/