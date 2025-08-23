#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;
// n가지의 종류의 동전으로 k원이 되도록 구성하기 (경우의 수)
// 사용한 동전의 순서는 구분하지 않는다.
int n, k;

vector<int> coin(100);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }

    sort(coin.begin(), coin.begin() + n);
    vector<int> dp(k + 1, 0);

    dp[0] = 1;
    for (int i = 0; i < n; i++) 
    {
        for (int j = coin[i]; j <= k; j++) 
        {
            dp[j] += dp[j - coin[i]];
        }
    }
    cout << dp[k] << '\n';
    return 0;
}