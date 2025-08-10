#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1001];
int dp[1001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int result = 1;
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1; // 자기 자신만 있는 경우
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        result = max(result, dp[i]);
    }

    cout << result;
    return 0;
}