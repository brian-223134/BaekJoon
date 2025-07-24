#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;
vector<int> dp(12, 0);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int test;
    cin >> test;
    dp[0] = 0; dp[1] = 1; dp[2] = 2; dp[3] = 4;
    
    for (int i = 4; i <= 11; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    for (int i = 0; i < test; i++)
    {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}