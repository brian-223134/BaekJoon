#include <iostream>
#include <algorithm>

using namespace std;

unsigned int N, K;
unsigned int list[10000];

bool possible(unsigned int length) {
    unsigned int count = 0;
    for (int i = 0; i < K; i++) {
        count += list[i] / length;
        if (count >= N) return true; // 조기 종료
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K >> N;

    unsigned int max_length = 0;
    for (int i = 0; i < K; i++) {
        cin >> list[i];
        max_length = max(max_length, list[i]);
    }

    unsigned int left = 1, right = max_length + 1;  // upper_bound 패턴: right는 +1

    while (left < right) {
        unsigned int mid = (left + right) / 2;

        if (possible(mid)) {
            left = mid + 1;  // mid는 가능 → 더 큰 길이를 시도
        }
        else {
            right = mid;     // mid는 불가능 → 더 짧은 길이로
        }
    }

    // left는 "불가능한 가장 작은 값", 따라서 정답은 left - 1
    cout << left - 1 << '\n';
    return 0;
}
