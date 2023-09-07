/*
<두 원 사이의 정수 쌍>

문제 설명
x축과 y축으로 이루어진 2차원 직교 좌표계에 중심이 원점인 서로 다른 크기의 원이 두 개 주어집니다. 반지름을 나타내는 두 정수 r1, r2가 매개변수로 주어질 때, 두 원 사이의 공간에 x좌표와 y좌표가 모두 정수인 점의 개수를 return하도록 solution 함수를 완성해주세요.
※ 각 원 위의 점도 포함하여 셉니다.

제한 사항
1 ≤ r1 < r2 ≤ 1,000,000

입출력 예
r1	r2	result
2	3	20
*/
#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    // x*x + y*y = r*r
    // so (x,y) is r1*r1 <= x*x + y*y <= r2*r2.
    // About each x, max y = sqrt(r*r - x*x)
    
    for(long long x = 1; x <= r2; x++){
        long long y2 = sqrt((long long)r2 * r2 - x * x);
        long long y1 = sqrt((long long)r1 * r1 - x * x);
        
        if(y1 * y1 + x * x == (long long)r1 * r1 && y1 != 0)
            y1 -= 1;
        
        long long y = y2 - y1;
        answer += y;
    }
    answer *= 4;                // Because of 1st, 2nd, 3rd, 4th quadrants
    answer += 4 * (r2 - r1+1);  // Points on the line

    return answer;
}
/*
#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    

    for (int x = 1; x <= r2; ++x)
    {
        int y2 = floor(sqrt(r2 * r2 - x * x));        
        int y1 = x < r1 ? ceil(sqrt(r1 * r1 - x * x)) : 0;        
        answer += y2 - y1 + 1;        
    }
    return 4 * answer;
}
*/