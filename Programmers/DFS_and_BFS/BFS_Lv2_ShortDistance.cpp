/*
게임 맵 최단거리

문제 설명
ROR 게임은 두 팀으로 나누어서 진행하며, 상대 팀 진영을 먼저 파괴하면 이기는 게임입니다. 
따라서, 각 팀은 상대 팀 진영에 최대한 빨리 도착하는 것이 유리합니다.

지금부터 당신은 한 팀의 팀원이 되어 게임을 진행하려고 합니다. 

게임 맵의 상태 maps가 매개변수로 주어질 때, 캐릭터가 상대 팀 진영에 도착하기 위해서 
지나가야 하는 칸의 개수의 최솟값을 return 하도록 solution 함수를 완성해주세요. 
단, 상대 팀 진영에 도착할 수 없을 때는 -1을 return 해주세요.

제한사항
maps는 n x m 크기의 게임 맵의 상태가 들어있는 2차원 배열로, n과 m은 각각 1 이상 100 이하의 자연수입니다.
n과 m은 서로 같을 수도, 다를 수도 있지만, n과 m이 모두 1인 경우는 입력으로 주어지지 않습니다.
maps는 0과 1로만 이루어져 있으며, 0은 벽이 있는 자리, 1은 벽이 없는 자리를 나타냅니다.
처음에 캐릭터는 게임 맵의 좌측 상단인 (1, 1) 위치에 있으며, 상대방 진영은 게임 맵의 우측 하단인 (n, m) 위치에 있습니다.

입출력 예
maps	answer
[[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,1],[0,0,0,0,1]]	11
[[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,0],[0,0,0,0,1]]	-1
*/
#include <vector>
#include <queue>
using namespace std;

struct Point {
    int x, y;
};

int bfs(vector<vector<int>> maps, Point start, Point end, vector<vector<bool>> visited) {
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int n = maps.size();
    int m = maps[0].size();

    queue<Point> q;
    q.push(start);
    visited[start.x][start.y] = true;

    while (!q.empty()) {
        Point current_pnt = q.front(); // current node
        q.pop();
        
        if (current_pnt.x == end.x && current_pnt.y == end.y) {
            return maps[current_pnt.x][current_pnt.y];
        }

        for (int i = 0; i < 4; ++i) {
            int nx = current_pnt.x + dx[i];
            int ny = current_pnt.y + dy[i];

            if (nx >= 0 && nx < n && 
                ny >= 0 && ny < m && 
                maps[nx][ny] == 1 &&
                !visited[nx][ny]) {
                
                q.push({nx, ny});
                maps[nx][ny] = maps[current_pnt.x][current_pnt.y] + 1;
                visited[nx][ny] = true;
            }
        }
    }

    return -1; // 도착할 수 없는 경우
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    // define start and end point
    Point start = {0, 0};
    Point end = {n - 1, m - 1};
    
    return bfs(maps, start, end, visited);
}