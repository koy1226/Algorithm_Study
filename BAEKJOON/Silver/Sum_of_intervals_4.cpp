/*
구간 합 구하기 4
시간 제한	메모리 제한      정답 비율
1 초	    256 MB	        39.437%

문제
수 N개가 주어졌을 때, i번째 수부터 j번째 수까지 합을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N과 합을 구해야 하는 횟수 M이 주어진다. 둘째 줄에는 N개의 수가 주어진다. 수는 1,000보다 작거나 같은 자연수이다. 셋째 줄부터 M개의 줄에는 합을 구해야 하는 구간 i와 j가 주어진다.

출력
총 M개의 줄에 입력으로 주어진 i번째 수부터 j번째 수까지 합을 출력한다.

제한
1 ≤ N ≤ 100,000
1 ≤ M ≤ 100,000
1 ≤ i ≤ j ≤ N
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;

    vector<int> num(N);
    vector<int> pre_sum(N + 1, 0);

    for (int i = 0; i < N; i++) {
        cin >> num[i];
        pre_sum[i + 1] = pre_sum[i] + num[i];
    }

    for (int i = 0; i < M; i++) {
        int start, end;
        cin >> start >> end;
        cout << pre_sum[end] - pre_sum[start - 1] << '\n';
    }

    return 0;
}