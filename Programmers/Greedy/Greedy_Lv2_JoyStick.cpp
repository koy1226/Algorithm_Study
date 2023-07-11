/*
<조이스틱>

문제 설명
조이스틱으로 알파벳 이름을 완성하세요. 맨 처음엔 A로만 이루어져 있습니다.
ex) 완성해야 하는 이름이 세 글자면 AAA, 네 글자면 AAAA

조이스틱을 각 방향으로 움직이면 아래와 같습니다.

▲ - 다음 알파벳
▼ - 이전 알파벳 (A에서 아래쪽으로 이동하면 Z로)
◀ - 커서를 왼쪽으로 이동 (첫 번째 위치에서 왼쪽으로 이동하면 마지막 문자에 커서)
▶ - 커서를 오른쪽으로 이동 (마지막 위치에서 오른쪽으로 이동하면 첫 번째 문자에 커서)
예를 들어 아래의 방법으로 "JAZ"를 만들 수 있습니다.

- 첫 번째 위치에서 조이스틱을 위로 9번 조작하여 J를 완성합니다.
- 조이스틱을 왼쪽으로 1번 조작하여 커서를 마지막 문자 위치로 이동시킵니다.
- 마지막 위치에서 조이스틱을 아래로 1번 조작하여 Z를 완성합니다.
따라서 11번 이동시켜 "JAZ"를 만들 수 있고, 이때가 최소 이동입니다.
만들고자 하는 이름 name이 매개변수로 주어질 때, 이름에 대해 조이스틱 조작 횟수의 최솟값을 return 하도록 solution 함수를 만드세요.

제한 사항
name은 알파벳 대문자로만 이루어져 있습니다.
name의 길이는 1 이상 20 이하입니다.

입출력 예
name	        return
"JEROEN"	    56
"JAN"	        23
"CANAAAAANAN"   48
*/
//방법1)
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int length = name.length();
    int move = length - 1; // 커서를 오른쪽으로만 이동하는 경우를 기본으로 설정

    for (int i = 0; i < length; i++) {
        int up_down = min(name[i] - 'A', 'Z' - name[i] + 1); // 위, 아래 중에서 더 가까운 쪽을 찾음
        answer += up_down;

        int next = i + 1;
        while (next < length && name[next] == 'A') // 다음으로 변경해야 할 알파벳 위치를 찾음
            next++;

        move = min(move, i + length - next + min(i, length - next)); // 현재 위치를 기준으로 왼쪽, 오른쪽 중에서 더 가까운 쪽을 찾음
    }

    answer += move;
    return answer;
}

/*
방법2)
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