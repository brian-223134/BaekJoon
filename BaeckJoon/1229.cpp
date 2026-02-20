#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1000000;
int dp[MAX_N + 1];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // 1. 1,000,000 이하의 모든 육각수 구하기
    vector<int> hex_nums;
    for (int i = 1; ; i++) {
        int h = i * (2 * i - 1);
        if (h > MAX_N) break;
        hex_nums.push_back(h);
    }

    // 2. DP 배열 초기화 (충분히 큰 값으로 설정)
    for (int i = 1; i <= n; i++) {
        dp[i] = 1e9;
    }
    dp[0] = 0; // 0을 만드는 데 필요한 육각수는 0개

    // 3. DP 진행
    for (int i = 1; i <= n; i++) {
        for (int h : hex_nums) {
            if (h > i) break; // 현재 수 i보다 육각수가 크면 더 이상 뺄 수 없으므로 종료
            dp[i] = min(dp[i], dp[i - h] + 1);
        }
    }

    // 결과 출력
    cout << dp[n] << "\n";

    return 0;
}