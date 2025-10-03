#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
#include <climits>

using namespace std;

int n;
long long dp[500][500];
// dp[i][j]: i번째 행렬부터 j번째 행렬까지의 곱을 구할 때의 최소 연산 횟수

int main(void)
{
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    vector<pair<int, int>> matrix(n);

    for (int i = 0; i < n; i++)
    {
        cin >> matrix[i].first >> matrix[i].second;
        dp[i][i] = 0; // 자기 자신과의 곱은 연산 횟수 0
    }

    // len은 곱하는 행렬 체인의 길이 (2부터 n까지)
    for (int len = 2; len <= n; len++)
    {
        // i는 시작 행렬의 인덱스
        for (int i = 0; i <= n - len; i++)
        {
            // j는 끝 행렬의 인덱스
            int j = i + len - 1;


            dp[i][j] = LLONG_MAX;

            // k는 행렬 체인을 나누는 분할 지점 (A_i ... A_k) * (A_{k+1} ... A_j)
            for (int k = i; k < j; k++)
            {
                // 현재 분할 지점 k에서의 연산 횟수
                // DP[i][k] + DP[k+1][j] + A_i 행 * A_k 열 * A_j 열
                long long cost = dp[i][k] + dp[k + 1][j] + (long long)matrix[i].first * matrix[k].second * matrix[j].second;

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    cout << dp[0][n - 1] << "\n";

    return 0;
}