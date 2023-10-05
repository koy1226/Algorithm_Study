/*
<무인도 여행>

문제 설명
메리는 여름을 맞아 무인도로 여행을 가기 위해 지도를 보고 있습니다. 지도에는 바다와 무인도들에 대한 정보가 표시돼 있습니다. 지도는 1 x 1크기의 사각형들로 이루어진 직사각형 격자 형태이며, 격자의 각 칸에는 'X' 또는 1에서 9 사이의 자연수가 적혀있습니다. 지도의 'X'는 바다를 나타내며, 숫자는 무인도를 나타냅니다. 이때, 상, 하, 좌, 우로 연결되는 땅들은 하나의 무인도를 이룹니다. 지도의 각 칸에 적힌 숫자는 식량을 나타내는데, 상, 하, 좌, 우로 연결되는 칸에 적힌 숫자를 모두 합한 값은 해당 무인도에서 최대 며칠동안 머물 수 있는지를 나타냅니다. 어떤 섬으로 놀러 갈지 못 정한 메리는 우선 각 섬에서 최대 며칠씩 머물 수 있는지 알아본 후 놀러갈 섬을 결정하려 합니다.

지도를 나타내는 문자열 배열 maps가 매개변수로 주어질 때, 각 섬에서 최대 며칠씩 머무를 수 있는지 배열에 오름차순으로 담아 return 하는 solution 함수를 완성해주세요. 만약 지낼 수 있는 무인도가 없다면 -1을 배열에 담아 return 해주세요.

제한사항
3 ≤ maps의 길이 ≤ 100
3 ≤ maps[i]의 길이 ≤ 100
maps[i]는 'X' 또는 1 과 9 사이의 자연수로 이루어진 문자열입니다.
지도는 직사각형 형태입니다.

입출력 예
maps	result
["X591X","X1X5X","X231X", "1XXX1"]	[1, 1, 27]
["XXX","XXX","XXX"]	[-1]
*/
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct point {
    int x;
    int y;
};

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int n = maps.size(), m = maps[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m,false));
    stack<point> s;     // create stack
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maps[i][j] != 'X' && !visited[i][j]) {
                s.push({i, j});
                visited[i][j] = true;
                int sum = 0;
                
                 while (!s.empty()) {
                    point cur_point = s.top();
                    s.pop();
                    sum += maps[cur_point.x][cur_point.y] - '0';    //char to int 

                    visited[cur_point.x][cur_point.y] = true;

                    for (int i = 0; i < 4; i++) {
                        int nx = cur_point.x + dx[i];
                        int ny = cur_point.y + dy[i];

                        if (nx >= 0 && nx < n && ny >= 0 && ny < m 
                            && !visited[nx][ny] && maps[nx][ny] != 'X') {
                            s.push({nx, ny});
                            visited[nx][ny] = true;

                        }
                    }
                }
                answer.push_back(sum);
            }
        }
    }
    
    if (answer.empty()) {
        return {-1};
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}
/* Case 2 : Recursion
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

int dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y) {
    int days = grid[x][y];
    visited[x][y] = true;

    for (int i = 0; i < 4; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        
        if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && !visited[newX][newY] && grid[newX][newY] != -1) {
            days += dfs(grid, visited, newX, newY);
        }
    }
    return days;
}

vector<int> solution(vector<string> maps) {
    int rows = maps.size();
    int cols = maps[0].size();
    vector<vector<int>> grid(rows, vector<int>(cols, -1));
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<int> answer;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (maps[i][j] != 'X') {
                grid[i][j] = maps[i][j] - '0';
            }
        }
    }
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!visited[i][j] && grid[i][j] != -1) {
                int days = dfs(grid, visited, i, j);
                answer.push_back(days);
            }
        }
    }

    if (answer.empty()) {
        return {-1};
    }
    sort(answer.begin(), answer.end());
    return answer;
}

*/