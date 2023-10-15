/*
문제
수 N개 A1, A2, ..., AN이 주어진다. 이때, 연속된 부분 구간의 합이 M으로 나누어 떨어지는 구간의 개수를 구하는 프로그램을 작성하시오.
즉, Ai + ... + Aj (i ≤ j) 의 합이 M으로 나누어 떨어지는 (i, j) 쌍의 개수를 구해야 한다.

입력
첫째 줄에 N과 M이 주어진다. (1 ≤ N ≤ 106, 2 ≤ M ≤ 103)
둘째 줄에 N개의 수 A1, A2, ..., AN이 주어진다. (0 ≤ Ai ≤ 109)

출력
첫째 줄에 연속된 부분 구간의 합이 M으로 나누어 떨어지는 구간의 개수를 출력한다.
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N, M;
    cin >> N >> M;

    vector<long long> arr(N);
    for (long long i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    long long sum = 0;
    long long count = 0;
    unordered_map<long long, long long> remainders;

    // 초기 0값에 대한 카운트
    remainders[0] = 1;

    for (long long i = 0; i < N; ++i) {
        sum += arr[i];
        sum %= M;

        // sum % M이 같은 값을 가지는 경우를 카운트
        if (remainders.find(sum) != remainders.end()) {
            count += remainders[sum];
        }

        // 현재의 sum % M 값을 저장 또는 카운트 증가
        ++remainders[sum];
    }

    cout << count << endl;

    return 0;
}