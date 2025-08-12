#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int dp[10001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    // 동일 가치의 동전은 하나로 본다
    unordered_set<int> kinds;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        kinds.insert(temp);
    }

    vector<int> kind_vec(kinds.begin(), kinds.end());
    sort(kind_vec.begin(), kind_vec.end());

    fill(dp, dp + k + 1, 10001);
    dp[0] = 0;

    for (int coin : kind_vec)
    {
        for (int i = coin; i <= k; i++) 
        {
            dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }

    cout << (dp[k] == 10001 ? -1 : dp[k]) << '\n';
    return 0;
}