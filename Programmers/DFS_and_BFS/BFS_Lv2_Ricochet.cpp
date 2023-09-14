/*
<리코쳇 로봇>

문제 설명
리코쳇 로봇이라는 보드게임이 있습니다.

이 보드게임은 격자모양 게임판 위에서 말을 움직이는 게임으로, 시작 위치에서 목표 위치까지 최소 몇 번만에 도달할 수 있는지 말하는 게임입니다.

이 게임에서 말의 움직임은 상, 하, 좌, 우 4방향 중 하나를 선택해서 게임판 위의 장애물이나 맨 끝에 부딪힐 때까지 미끄러져 이동하는 것을 한 번의 이동으로 칩니다.

다음은 보드게임판을 나타낸 예시입니다.

...D..R
.D.G...
....D.D
D....D.
..D....
여기서 "."은 빈 공간을, "R"은 로봇의 처음 위치를, "D"는 장애물의 위치를, "G"는 목표지점을 나타냅니다.
위 예시에서는 "R" 위치에서 아래, 왼쪽, 위, 왼쪽, 아래, 오른쪽, 위 순서로 움직이면 7번 만에 "G" 위치에 멈춰 설 수 있으며, 이것이 최소 움직임 중 하나입니다.

게임판의 상태를 나타내는 문자열 배열 board가 주어졌을 때, 말이 목표위치에 도달하는데 최소 몇 번 이동해야 하는지 return 하는 solution함수를 완성하세요. 만약 목표위치에 도달할 수 없다면 -1을 return 해주세요.

제한 사항
3 ≤ board의 길이 ≤ 100
3 ≤ board의 원소의 길이 ≤ 100
board의 원소의 길이는 모두 동일합니다.
문자열은 ".", "D", "R", "G"로만 구성되어 있으며 각각 빈 공간, 장애물, 로봇의 처음 위치, 목표 지점을 나타냅니다.
"R"과 "G"는 한 번씩 등장합니다.

입출력 예
board	result
["...D..R", ".D.G...", "....D.D", "D....D.", "..D...."]	7
[".D.R", "....", ".G..", "...D"]	-1
*/
// Case 1
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct location {
    int x;
    int y;
    int move_cnt;
};

int bfs(vector<string> board, location start, location end, vector<vector<bool>>& visited) {
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int n = board.size();
    int m = board[0].size();

    queue<location> q;
    start.move_cnt = 0;
    q.push(start);
    visited[start.x][start.y] = true;

    while (!q.empty()) {
        location current = q.front(); // current location
        q.pop();
        
        if (current.x == end.x && current.y == end.y) {
            return current.move_cnt;
        }

        for (int i = 0; i < 4; ++i) {
            // 맨 끝에 부딪힐 때까지 미끄러져서 한 칸씩 이동 x
            // int nx = current.x + dx[i];
            // int ny = current.y + dy[i];
            int nx = current.x;
            int ny = current.y;
            
            // 장애물 만나면 루프 아웃
            while(nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] != 'D') {
                nx += dx[i];
                ny += dy[i];
            }
            
            // 한칸 뒤로
            nx -= dx[i];
            ny -= dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                
                q.push({nx, ny, current.move_cnt + 1});
                //board[nx][ny] = board[current.x][current.y] + 1;
                visited[nx][ny] = true;
            }
        }
    }

    return -1; // 도착할 수 없는 경우
}

int solution(vector<string> board) {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    location start = {0, 0, 0};
    location end = {0, 0, 0};
    
    // define start and end point
    for (int i =0; i < n; i++) {
        for (int j = 0; j < m; j++) { 
            if (board[i][j] == 'R') {
                start = {i, j};
            }
            if (board[i][j] == 'G') {
                end = {i, j};
            }
        }
    }

    
    answer = bfs(board, start, end, visited);
    return answer;
}