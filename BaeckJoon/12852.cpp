#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1000001];
int from[1000001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    dp[1] = 0;
    from[1] = 0; // 1은 시작점

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1;
        from[i] = i - 1;

        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) 
        {
            dp[i] = dp[i / 2] + 1;
            from[i] = i / 2;
        }
        if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) 
        {
            dp[i] = dp[i / 3] + 1;
            from[i] = i / 3;
        }
    }

    cout << dp[n] << '\n';

    // 경로 역추적
    vector<int> procedure;
    for (int i = n; i != 0; i = from[i]) 
    {
        procedure.push_back(i);
    }
    for (auto it = procedure.begin(); it != procedure.end(); ++it) 
    {
        cout << *it << ' ';
    }
    cout << '\n';

    return 0;
}