/*
<호텔 대실>

문제 설명
호텔을 운영 중인 코니는 최소한의 객실만을 사용하여 예약 손님들을 받으려고 합니다. 
한 번 사용한 객실은 퇴실 시간을 기준으로 10분간 청소를 하고 다음 손님들이 사용할 수 있습니다.
예약 시각이 문자열 형태로 담긴 2차원 배열 book_time이 매개변수로 주어질 때, 
코니에게 필요한 최소 객실의 수를 return 하는 solution 함수를 완성해주세요.

제한사항
1 ≤ book_time의 길이 ≤ 1,000
book_time[i]는 ["HH:MM", "HH:MM"]의 형태로 이루어진 배열입니다
[대실 시작 시각, 대실 종료 시각] 형태입니다.
시각은 HH:MM 형태로 24시간 표기법을 따르며, "00:00" 부터 "23:59" 까지로 주어집니다.
예약 시각이 자정을 넘어가는 경우는 없습니다.
시작 시각은 항상 종료 시각보다 빠릅니다.

입출력 예
book_time	result
[["15:00", "17:00"], ["16:40", "18:20"], ["14:20", "15:20"], ["14:10", "19:20"], ["18:20", "21:20"]]	3
[["09:10", "10:10"], ["10:20", "12:20"]]	1
[["10:20", "12:30"], ["10:20", "12:30"], ["10:20", "12:30"]]	3
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int time2min(string &bt) {
    int hour = stoi(bt.substr(0, 2));
    int minute = stoi(bt.substr(3, 2));
    return hour * 60 + minute;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<bool> used(book_time.size(), false);
    vector<pair<int, int>> time_intervals;
    
    int min_s = 0, min_e = 0;
    for (vector<string> bt : book_time) {
        int start = time2min(bt[0]);
        int end = time2min(bt[1]) + 10;
        time_intervals.push_back({start, 1});
        time_intervals.push_back({end, -1});
    }
    sort(time_intervals.begin(), time_intervals.end());
    
    int cur_room = 0;
    
    for (auto interval : time_intervals) {
        cur_room += interval.second;
        answer = max(answer, cur_room);
    }
    
    return answer;
}