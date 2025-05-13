#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int L[21], J[21];
    for (int i = 0; i < N; i++) cin >> L[i];
    for (int i = 0; i < N; i++) cin >> J[i];

    int dp[101] = { 0 }; // ü�� 1~100 �Ҹ� �� �ִ� ��� ����

    for (int i = 0; i < N; i++) {
        for (int j = 100; j >= L[i]; j--) {
            dp[j] = max(dp[j], dp[j - L[i]] + J[i]);
        }
    }

    int answer = 0;
    for (int i = 1; i < 100; i++) { // ü�� 100�� �ʰ��ϸ� �� ��
        answer = max(answer, dp[i]);
    }

    cout << answer << '\n';
    return 0;
}