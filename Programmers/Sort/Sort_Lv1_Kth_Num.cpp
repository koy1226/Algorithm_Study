/*

*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp_v;
    for (int a = 0; a < commands.size(); a++) {
        int i = commands[a][0] - 1;
        int j = commands[a][1] - 1;
        int k = commands[a][2] - 1;
        for (int b = i; b < j + 1; b++) {
            temp_v.push_back(array[b]);
        }
        sort(temp_v.begin(), temp_v.end());
        int temp = temp_v[k];
        answer.push_back(temp);
        temp_v.clear();
    }

    return answer;
}

/*
¹æ¹ý2)
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;

    for(int i = 0; i < commands.size(); i++) {
        temp = array;
        sort(temp.begin() + commands[i][0] - 1, temp.begin() + commands[i][1]);
        answer.push_back(temp[commands[i][0] + commands[i][2]-2]);
    }

    return answer;
}
*/