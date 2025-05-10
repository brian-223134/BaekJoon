#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> budget(n);
    int total = 0, max_req = 0;

    for (int i = 0; i < n; ++i) {
        cin >> budget[i];
        max_req = max(max_req, budget[i]);
    }

    int m;
    cin >> m;

    // 요청의 합이 예산보다 작거나 같으면 최대값 출력
    int sum = 0;
    for (int i = 0; i < n; ++i) sum += budget[i];
    if (sum <= m) {
        cout << max_req;
        return 0;
    }

    // 이분 탐색 시작
    int left = 0, right = max_req;
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        long long total_alloc = 0;
        for (int i = 0; i < n; ++i)
            total_alloc += min(budget[i], mid);

        if (total_alloc <= m) {
            answer = mid;          // 가능한 상한선 후보
            left = mid + 1;        // 더 큰 상한선 탐색
        }
        else {
            right = mid - 1;       // 너무 많이 배정됨 → 줄이기
        }
    }

    cout << answer;
    return 0;
}