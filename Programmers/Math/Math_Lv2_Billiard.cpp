/*
<당구 연습>

문제 설명
프로그래머스의 마스코트인 머쓱이는 최근 취미로 당구를 치기 시작했습니다.

머쓱이는 손 대신 날개를 사용해야 해서 당구를 잘 못 칩니다. 
하지만 끈기가 강한 머쓱이는 열심히 노력해서 당구를 잘 치려고 당구 학원에 다니고 있습니다.

오늘도 당구 학원에 나온 머쓱이에게 당구 선생님이"원쿠션"(당구에서 공을 쳐서 벽에 맞히는 걸 쿠션이라고 부르고, 
벽에 한 번 맞힌 후 공에 맞히면 원쿠션이라고 부릅니다) 연습을 하라면서 당구공의 위치가 담긴 리스트를 건네줬습니다. 
리스트에는 머쓱이가 맞춰야 하는 공들의 위치가 담겨있습니다. 머쓱이는 리스트에 담긴 각 위치에 순서대로 공을 놓아가며 "원쿠션" 연습을 하면 됩니다. 
이때, 머쓱이는 항상 같은 위치에 공을 놓고 쳐서 리스트에 담긴 위치에 놓인 공을 맞춥니다.

머쓱이와 달리 최근 취미로 알고리즘 문제를 풀기 시작한 당신은, 머쓱이가 친 공이 각각의 목표로한 공에 맞을 때까지 최소 얼마의 거리를 굴러가야 하는지가 궁금해졌습니다.

당구대의 가로 길이 m, 세로 길이 n과 머쓱이가 쳐야 하는 공이 놓인 위치 좌표를 나타내는 두 정수 startX, startY, 
그리고 매 회마다 목표로 해야하는 공들의 위치 좌표를 나타내는 정수 쌍들이 들어있는 2차원 정수배열 balls가 주어집니다. 
"원쿠션" 연습을 위해 머쓱이가 공을 적어도 벽에 한 번은 맞춘 후 목표 공에 맞힌다고 할 때, 
각 회마다 머쓱이가 친 공이 굴러간 거리의 최솟값의 제곱을 배열에 담아 return 하도록 solution 함수를 완성해 주세요.

단, 머쓱이가 친 공이 벽에 부딪힐 때 진행 방향은 항상 입사각과 반사각이 동일하며, 만약 꼭짓점에 부딪힐 경우 진입 방향의 반대방향으로 공이 진행됩니다. 
공의 크기는 무시하며, 두 공의 좌표가 정확히 일치하는 경우에만 두 공이 서로 맞았다고 판단합니다. 
공이 목표 공에 맞기 전에 멈추는 경우는 없으며, 목표 공에 맞으면 바로 멈춘다고 가정합니다.

제한사항
3 ≤ m, n ≤ 1,000
0 < startX < m
0 < startY < n
2 ≤ balls의 길이 ≤ 1,000
balls의 원소는 [a, b] 형태입니다.
a, b는 머쓱이가 맞춰야 할 공이 놓인 좌표를 의미합니다.
0 < a < m, 0 < b < n
(a, b) = ( startX, startY )인 입력은 들어오지 않습니다.

입출력 예
m	n	startX	startY	balls	result
10	10	3	7	[[7, 7], [2, 7], [7, 3]]	[52, 37, 116]
*/
// Case 1
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

struct Point {
    float x, y;
};

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    for (const vector<int> &ball : balls) {
        int minDistance = INT_MAX;
        vector<Point> reflections;

        if (ball[0] != startX || ball[1] > startY) 
            reflections.push_back({static_cast<float>(ball[0]), static_cast<float>(-ball[1])});
        if (ball[0] != startX || ball[1] < startY)
            reflections.push_back({static_cast<float>(ball[0]), static_cast<float>(2 * n - ball[1])});
        if (ball[1] != startY || ball[0] > startX) 
            reflections.push_back({static_cast<float>(-ball[0]), static_cast<float>(ball[1])});
        if (ball[1] != startY || ball[0] < startX) 
            reflections.push_back({static_cast<float>(2 * m - ball[0]), static_cast<float>(ball[1])});

        for (const Point &reflection : reflections) {
            int diffX = abs(startX - static_cast<int>(reflection.x));
            int diffY = abs(startY - static_cast<int>(reflection.y));
            int distance = diffX * diffX + diffY * diffY;
            minDistance = min(minDistance, distance);
        }

        answer.push_back(minDistance);
    }

    return answer;
}

/* Case 2
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> ret;

    auto dist = [&](int x, int y) -> int {
        int dx = startX - x;
        int dy = startY - y;
        return dx * dx + dy * dy;
    };

    for (auto& b : balls) {
        int sub = 0x3f3f3f3f;

        if (startX != b[0] || startY < b[1]) sub = min(sub, dist(b[0], -b[1]));
        if (startX != b[0] || startY > b[1]) sub = min(sub, dist(b[0], 2 * n - b[1]));
        if (startY != b[1] || startX < b[0]) sub = min(sub, dist(-b[0], b[1]));
        if (startY != b[1] || startX > b[0]) sub = min(sub, dist(2 * m - b[0], b[1]));

        ret.push_back(sub);
    }

    return ret;
}
*/
/* Case 3
#include <string>
#include <vector>
#include <cmath>

using namespace std;

enum DIR{UP = 0, DOWN, LEFT, RIGHT, DIR_MAX};

int Distance(int _iWidth, int _iHeight)
{
    return pow(_iWidth, 2) + pow(_iHeight, 2);
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) 
{
    vector<int> answer;
    for (const auto& ball : balls)
    {
        int arrDis[4] = { 0, };

        arrDis[UP] = Distance(abs(startX - ball[0]), (n - ball[1]) + (n - startY));
        arrDis[DOWN] = Distance(abs(startX - ball[0]), ball[1] + startY);
        arrDis[LEFT] = Distance(abs(startY - ball[1]), ball[0] + startX);
        arrDis[RIGHT] = Distance(abs(startY - ball[1]), (m - ball[0]) + (m - startX));

        int iMin = -1;
        if (startX == ball[0])
        {
            iMin = min(arrDis[LEFT], arrDis[RIGHT]);
            if (startY < ball[1])
                iMin = min(iMin, arrDis[DOWN]);
            else
                iMin = min(iMin, arrDis[UP]);
        }
        else if (startY == ball[1])
        {
            iMin = min(arrDis[UP], arrDis[DOWN]);
            if (startX < ball[0])
                iMin = min(iMin, arrDis[LEFT]);
            else
                iMin = min(iMin, arrDis[RIGHT]);
        }
        else
        {
            iMin = min(arrDis[UP], arrDis[DOWN]);
            for (int i = LEFT; i < DIR_MAX; ++i)
                iMin = min(iMin, arrDis[i]);
        }

        answer.emplace_back(iMin);
    }
    return answer;
}
*/