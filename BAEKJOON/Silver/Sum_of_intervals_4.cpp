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