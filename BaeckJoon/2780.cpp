#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1234567;

vector<vector<int>> moves = {
    {7},        // 0
    {2, 4},     // 1
    {1, 3, 5},  // 2
    {2, 6},     // 3
    {1, 5, 7},  // 4
    {2, 4, 6, 8}, // 5
    {3, 5, 9},  // 6
    {4, 8, 0},  // 7
    {5, 7, 9},  // 8
    {6, 8}      // 9
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<vector<int>> dp(n + 1, vector<int>(10, 0));

        for (int i = 0; i <= 9; i++)
            dp[1][i] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= 9; j++) {
                for (int prev : moves[j]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][prev]) % MOD;
                }
            }
        }

        int total = 0;
        for (int i = 0; i <= 9; i++)
            total = (total + dp[n][i]) % MOD;

        cout << total << endl;
    }

    return 0;
}