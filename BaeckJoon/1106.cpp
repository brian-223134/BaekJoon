#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int c, n; // c: �÷����ϴ� �� ��, n: ���� ����

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> c >> n;
    vector<pair<int, int>> cost(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i].first >> cost[i].second; // {���, �� ��ġ ��}
    }

    const int INF = 1e9;
    vector<int> dp(c + 101, INF); // �ִ� �� ���� �˳��� ����
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        int city_cost = cost[i].first;
        int city_cust = cost[i].second;
        for (int j = city_cust; j < dp.size(); j++)
        {
            dp[j] = min(dp[j], dp[j - city_cust] + city_cost);
        }
    }

    int answer = INF;
    for (int i = c; i < dp.size(); i++)
    {
        answer = min(answer, dp[i]);
    }
    cout << answer << '\n';

    return 0;
}