/*
<미로 탈출>

문제 설명
1 x 1 크기의 칸들로 이루어진 직사각형 격자 형태의 미로에서 탈출하려고 합니다. 
각 칸은 통로 또는 벽으로 구성되어 있으며, 벽으로 된 칸은 지나갈 수 없고 통로로 된 칸으로만 이동할 수 있습니다. 
통로들 중 한 칸에는 미로를 빠져나가는 문이 있는데, 이 문은 레버를 당겨서만 열 수 있습니다. 레버 또한 통로들 중 한 칸에 있습니다.
 따라서, 출발 지점에서 먼저 레버가 있는 칸으로 이동하여 레버를 당긴 후 미로를 빠져나가는 문이 있는 칸으로 이동하면 됩니다. 
 이때 아직 레버를 당기지 않았더라도 출구가 있는 칸을 지나갈 수 있습니다. 미로에서 한 칸을 이동하는데 1초가 걸린다고 할 때, 최대한 빠르게 미로를 빠져나가는데 걸리는 시간을 구하려 합니다.

미로를 나타낸 문자열 배열 maps가 매개변수로 주어질 때, 미로를 탈출하는데 필요한 최소 시간을 return 하는 solution 함수를 완성해주세요. 
만약, 탈출할 수 없다면 -1을 return 해주세요.

제한사항
5 ≤ maps의 길이 ≤ 100
5 ≤ maps[i]의 길이 ≤ 100
maps[i]는 다음 5개의 문자들로만 이루어져 있습니다.
S : 시작 지점
E : 출구
L : 레버
O : 통로
X : 벽
시작 지점과 출구, 레버는 항상 다른 곳에 존재하며 한 개씩만 존재합니다.
출구는 레버가 당겨지지 않아도 지나갈 수 있으며, 모든 통로, 출구, 레버, 시작점은 여러 번 지나갈 수 있습니다.

입출력 예
maps	result
["SOOOL","XXXXO","OOOOO","OXXXX","OOOOE"]	16
["LOOXS","OOOOX","OOOOO","OOOOO","EOOOO"]	-1
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Point{
    int x;
    int y;
    int move_cnt;
};

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int solution(vector<string> maps) {
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    queue<Point> q; // x, y
    Point start;
    Point end;
    Point lever;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maps[i][j] == 'S') {
                start = {j, i, 0};
                q.push(start);
                visited[i][j] = true;
            } else if (maps[i][j] == 'E') {
                end = {j, i, 0};
            } else if (maps[i][j] == 'L') {
                lever = {j, i, 0};
            }
        }
    }
    // 레버 찾기
    while (!q.empty()) {
        Point c = q.front();
        q.pop();

        if (c.x == lever.x && c.y == lever.y) { 
            // L을 찾고 Queue 클리어 후 초기화.
            q = queue<Point>();
            q.push(c);
            visited = vector<vector<bool>>(n, vector<bool>(m, false));
            visited[c.y][c.x] = true;
            break;
        }
        for (int dir = 0; dir < 4; dir++) {
            int nx = c.x + dx[dir];
            int ny = c.y + dy[dir];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[ny][nx] && maps[ny][nx] != 'X') {
                q.push({nx, ny, c.move_cnt + 1});
                visited[ny][nx] = true;
            }
        }
    }
    // 탈출구 찾기
    while (!q.empty()) {
        Point c = q.front();
        q.pop();

        if (c.x == end.x && c.y == end.y) {
            return c.move_cnt;
        }

        for (int dir = 0; dir < 4; dir++) {
            // 일반 이동
            int nx = c.x + dx[dir];
            int ny = c.y + dy[dir];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[ny][nx] && maps[ny][nx] != 'X') {
                q.push({nx, ny, c.move_cnt + 1});
                visited[ny][nx] = true;
            }

        }
    }
    return -1;
}