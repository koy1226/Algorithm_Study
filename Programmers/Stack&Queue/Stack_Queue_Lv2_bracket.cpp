/*
<올바른 괄호>

문제 설명
괄호가 바르게 짝지어졌다는 것은 '(' 문자로 열렸으면 반드시 짝지어서 ')' 문자로 닫혀야 한다는 뜻입니다. 예를 들어

"()()" 또는 "(())()" 는 올바른 괄호입니다.
")()(" 또는 "(()(" 는 올바르지 않은 괄호입니다.
'(' 또는 ')' 로만 이루어진 문자열 s가 주어졌을 때, 문자열 s가 올바른 괄호이면 true를 return 하고, 올바르지 않은 괄호이면 false를 return 하는 solution 함수를 완성해 주세요.

제한사항
문자열 s의 길이 : 100,000 이하의 자연수
문자열 s는 '(' 또는 ')' 로만 이루어져 있습니다.

입출력 예
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
방법2)
#include <string>

using namespace std;

bool solution(string s)
{
    int cnt = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            cnt++;
        } else {
            if (cnt == 0) //열린 괄호 없이 닫힌 괄호가 나왔는데, cnt가 0일때 false
                return false;
            cnt--;
        }
    }
    if (cnt != 0)
        return false;

    return cnt == 0;
}
*/