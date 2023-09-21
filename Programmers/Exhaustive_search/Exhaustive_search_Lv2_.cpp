/*
<카펫>

문제 설명
Leo는 카펫을 사러 갔다가 아래 그림과 같이 중앙에는 노란색으로 칠해져 있고 테두리 1줄은 갈색으로 칠해져 있는 격자 모양 카펫을 봤습니다.

carpet.png

Leo는 집으로 돌아와서 아까 본 카펫의 노란색과 갈색으로 색칠된 격자의 개수는 기억했지만, 전체 카펫의 크기는 기억하지 못했습니다.

Leo가 본 카펫에서 갈색 격자의 수 brown, 노란색 격자의 수 yellow가 매개변수로 주어질 때 카펫의 가로, 세로 크기를 순서대로 배열에 담아 return 하도록 solution 함수를 작성해주세요.

제한사항
갈색 격자의 수 brown은 8 이상 5,000 이하인 자연수입니다.
노란색 격자의 수 yellow는 1 이상 2,000,000 이하인 자연수입니다.
카펫의 가로 길이는 세로 길이와 같거나, 세로 길이보다 깁니다.

입출력 예
brown	yellow	return
10	2	[4, 3]
8	1	[3, 3]
24	24	[8, 6]
*/
// Case 1:
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    for (int a = 1; a <= sqrt(yellow); ++a) { // 노란색 격자의 가능한 세로 길이
        if (yellow % a != 0) continue;
        int b = yellow / a; // 노란색 격자의 가로 길이

        // 갈색 격자의 수를 계산
        int expectedBrown = 2 * (a + b) + 4;
        
        // 전체 카펫의 크기와 일치하는지 확인
        if (expectedBrown == brown) {
            answer.push_back(b + 2); // 전체 카펫의 가로 길이
            answer.push_back(a + 2); // 전체 카펫의 세로 길이
            break;
        }
    }
    
    return answer;
}
/* Case 2: 76.9 / 100.0
// 초기에 단순히 brown+yellow 약수의 관계로 문제를 해결하려고 했지만, 일부 테스트 케이스를 통과하지 못했다. 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<int> divisor;
    
    int sum = brown + yellow;
    for (int i = 1; i <= sum; i++) {
        if (sum % i == 0)
            divisor.push_back(i);
    }
    sort(divisor.begin(), divisor.end());
    int div_size = divisor.size();
    int mid_divisor = div_size / 2;
    if ((div_size % 2) == 0) {
        answer.push_back(divisor.at(mid_divisor));
        answer.push_back(divisor.at(mid_divisor - 1));
    } else {
        answer.push_back(divisor.at(mid_divisor));
        answer.push_back(divisor.at(mid_divisor));
    }
    
    return answer;
}
*/