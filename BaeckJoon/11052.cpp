#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int p[1001];
int dp[1001];

int main(void) 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> p[i];
    }

    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= i; j++) 
        {
            dp[i] = max(dp[i], dp[i - j] + p[j]);
        }
    }

    cout << dp[n] << '\n';
    return 0;
}