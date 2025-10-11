#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    const int MOD = 9901;
    int n;
    if (!(cin >> n)) return 0;

    // dp를 O(1) 메모리로 관리: a0=이전열(0), a1=이전열(1), a2=이전열(2)
    int a0 = 1, a1 = 0, a2 = 0; // dp[0] = [1,0,0]

    for (int i = 1; i <= n; i++)
    {
        int n0 = (a0 + a1 + a2) % MOD;
        int n1 = (a0 + a2) % MOD;
        int n2 = (a0 + a1) % MOD;
        a0 = n0; a1 = n1; a2 = n2;
    }

    int ans = (a0 + a1 + a2) % MOD;
    cout << ans << '\n';
    
    return 0;
}