/*
<과제 진행하기>

문제 설명
과제를 받은 루는 다음과 같은 순서대로 과제를 하려고 계획을 세웠습니다.

과제는 시작하기로 한 시각이 되면 시작합니다.
새로운 과제를 시작할 시각이 되었을 때, 기존에 진행 중이던 과제가 있다면 진행 중이던 과제를 멈추고 새로운 과제를 시작합니다.
진행중이던 과제를 끝냈을 때, 잠시 멈춘 과제가 있다면, 멈춰둔 과제를 이어서 진행합니다.
만약, 과제를 끝낸 시각에 새로 시작해야 되는 과제와 잠시 멈춰둔 과제가 모두 있다면, 새로 시작해야 하는 과제부터 진행합니다.
멈춰둔 과제가 여러 개일 경우, 가장 최근에 멈춘 과제부터 시작합니다.
과제 계획을 담은 이차원 문자열 배열 plans가 매개변수로 주어질 때, 과제를 끝낸 순서대로 이름을 배열에 담아 return 하는 solution 함수를 완성해주세요.

제한사항
3 ≤ plans의 길이 ≤ 1,000
plans의 원소는 [name, start, playtime]의 구조로 이루어져 있습니다.
name : 과제의 이름을 의미합니다.
2 ≤ name의 길이 ≤ 10
name은 알파벳 소문자로만 이루어져 있습니다.
name이 중복되는 원소는 없습니다.
start : 과제의 시작 시각을 나타냅니다.
"hh:mm"의 형태로 "00:00" ~ "23:59" 사이의 시간값만 들어가 있습니다.
모든 과제의 시작 시각은 달라서 겹칠 일이 없습니다.
과제는 "00:00" ... "23:59" 순으로 시작하면 됩니다. 즉, 시와 분의 값이 작을수록 더 빨리 시작한 과제입니다.
playtime : 과제를 마치는데 걸리는 시간을 의미하며, 단위는 분입니다.
1 ≤ playtime ≤ 100
playtime은 0으로 시작하지 않습니다.
배열은 시간순으로 정렬되어 있지 않을 수 있습니다.
진행중이던 과제가 끝나는 시각과 새로운 과제를 시작해야하는 시각이 같은 경우 진행중이던 과제는 끝난 것으로 판단합니다.

입출력 예
plans	result
[["korean", "11:40", "30"], ["english", "12:10", "20"], ["math", "12:30", "40"]]	["korean", "english", "math"]
[["science", "12:40", "50"], ["music", "12:20", "40"], ["history", "14:00", "30"], ["computer", "12:30", "100"]]	["science", "history", "computer", "music"]
[["aaa", "12:00", "20"], ["bbb", "12:10", "30"], ["ccc", "12:40", "10"]]	["bbb", "ccc", "aaa"]
*/
/*
초기 코드 문제점
1. 우선순위를 정해서 처리하려고 했으나, 
이 문제는 우선순위보다는 끝나는 시간과 수행 시간이 더 중요.
2. 끝난 작업을 처리하지 않음.
3. 우선 순위 계산법이 잘못됨.
    -> 우선 순위가 아니라 각 작업이 얼마나 많은 작업에 의해 중단되는지를 나타냄.
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int timeString2Int(const string& timeStr) {
    string newStr;
    for (char c : timeStr) {
        if (c != ':') {
            newStr += c;
        }
    }
    return stoi(newStr);
}

int Cal_endtime(int start, int running) {
    int minute = start % 100;
    int hour = start / 100;
    int end_time;

    if ((minute + running) >= 60) {
        hour += 1;
        minute = (minute + running) - 60;
    }
    else {
        minute = minute + running;
    }

    end_time = (hour * 100) + minute;

    return end_time;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    sort(plans.begin(), plans.end(), [](vector<string> a, vector<string> b) {
        return timeString2Int(a[1]) < timeString2Int(b[1]); 
    });
    
    int idx = 0;
    vector<int> priority(plans.size(), 0);
    while (idx < plans.size()) {
        string subject = plans[idx][0];
        int start_time = timeString2Int(plans[idx][1]);
        int running_time = stoi(plans[idx][2]);
        for (int i = idx+1; i < plans.size(); i++) {
            int end_time = Cal_endtime(start_time, running_time);
            if (end_time > timeString2Int(plans[i][1])) {
                priority[idx]++;
            }
        }
        idx++;                                                          
    }
    for (int pri : priority) {
        answer.push_back(plans[pri][0]);
    }
    
    return answer;
}
*/

#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

struct Task {
    string subject;
    int start_time;
    int running_time;
    bool operator<(const Task& theOther) const{
        return start_time > theOther.start_time;
    }
};

int timeString2Int(string& timeStr) {
    return stoi(timeStr.substr(0, 2)) * 60 + stoi(timeStr.substr(3, 2));
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    priority_queue<Task> tasks;
    stack<Task> paused_tasks;
    
    for (vector<string>& plan : plans) {
        string subject = plan[0];
        int start_time = timeString2Int(plan[1]);
        int running_time = stoi(plan[2]);
        tasks.push({subject, start_time, running_time});
    }

    Task current_task = {"", 0, 0};
    int current_time = 0;
    
    // 작업의 시간이 남았거나 작업 큐가 비어있지 않을 때
    while (current_task.running_time > 0 || !tasks.empty()) {
        // 작업 큐가 비어있지 않고 남은 다음 작업의 시작 시간이 현재 시간이랑 같을 때,
        if (!tasks.empty() && tasks.top().start_time == current_time) {
            // 현재 작업이 남아있을 때 중단 작업 스택에 현재 작업 Push
            if (current_task.running_time > 0) {
                paused_tasks.push(current_task);
            }
            // 현재 작업을 다음 작업으로 업데이트
            current_task = tasks.top();
            tasks.pop();
        }
        // 현재 작업 시간이 남아있으면 감소
        if (current_task.running_time > 0) {
            current_task.running_time--;
            //현재 업무가 종료되면 answer에 Push
            if (current_task.running_time == 0) {
                answer.push_back(current_task.subject);
                // 중단 업무 리스트가 비어있지 않으면 그 중단 업무를 다음 업무로 업데이트
                if (!paused_tasks.empty()) {
                    current_task = paused_tasks.top();
                    paused_tasks.pop();
                // 아니면 현재 업무 비워두기
                } else {
                    current_task = {"", 0, 0};
                }
            }
        }
        current_time++;
    }
    // 남아 있는 마지막 작업 처리
    while (!paused_tasks.empty()) {
            answer.push_back(paused_tasks.top().subject);
            paused_tasks.pop();
    }
        
    return answer;
}