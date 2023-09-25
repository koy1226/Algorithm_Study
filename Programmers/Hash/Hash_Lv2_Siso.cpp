/*
<시소 짝꿍>

문제 설명
어느 공원 놀이터에는 시소가 하나 설치되어 있습니다. 이 시소는 중심으로부터 2(m), 3(m), 4(m) 거리의 지점에 좌석이 하나씩 있습니다.
이 시소를 두 명이 마주 보고 탄다고 할 때, 시소가 평형인 상태에서 각각에 의해 시소에 걸리는 토크의 크기가 서로 상쇄되어 완전한 균형을 이룰 수 있다면 그 두 사람을 시소 짝꿍이라고 합니다. 즉, 탑승한 사람의 무게와 시소 축과 좌석 간의 거리의 곱이 양쪽 다 같다면 시소 짝꿍이라고 할 수 있습니다.
사람들의 몸무게 목록 weights이 주어질 때, 시소 짝꿍이 몇 쌍 존재하는지 구하여 return 하도록 solution 함수를 완성해주세요.

제한 사항
2 ≤ weights의 길이 ≤ 100,000
100 ≤ weights[i] ≤ 1,000
몸무게 단위는 N(뉴턴)으로 주어집니다.
몸무게는 모두 정수입니다.

입출력 예
weights	result
[100,180,360,100,270]	4
*/
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    long long n = weights.size();
    unordered_map<int, int> weight_cnt;
    
    // 무게별로 몇 개씩 있는지 센다.
    for (int weight : weights) {
        weight_cnt[weight]++;
    }
    
    // 같은 무게의 원소에 대한 조합을 더한다.
    for (auto [weight, cnt] : weight_cnt) {
        if (cnt >= 2) {
            answer += (long long)cnt * (cnt - 1) / 2;
        }
    }

    // 다른 무게의 원소에 대한 조합을 더한다.
    for(int weight : weights) {
        // 3:2 비율
        if ((weight * 3) % 2 == 0) {
            int paired_weight = (weight * 3) / 2;
            if(weight_cnt.find(paired_weight) != weight_cnt.end()) {
                answer += weight_cnt[paired_weight];
            }
        }
        
        // 4:3 비율
        if ((weight * 4) % 3 == 0) {
            int paired_weight = (weight * 4) / 3;
            if(weight_cnt.find(paired_weight) != weight_cnt.end()) {
                answer += weight_cnt[paired_weight];
            }
        }
        
        // 4:2 비율
        int paired_weight = weight * 2;
        if(weight_cnt.find(paired_weight) != weight_cnt.end()) {
            answer += weight_cnt[paired_weight];
        }
    }
    return answer;
}