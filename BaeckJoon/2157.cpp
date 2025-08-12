#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[301][301]; // dp[����][�湮�� ���� ��]
vector<pair<int, int>> graph[301]; // graph[u] = {v, ����}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) 
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (u < v) // �����������θ� �̵� ����
            graph[u].push_back({v, w});
    }

    memset(dp, -1, sizeof(dp));
    dp[1][1] = 0; // 1�� ���ÿ��� ����, �湮 ���� 1��

    for (int city = 1; city <= n; city++) 
    {
        for (int cnt = 1; cnt < m; cnt++) 
        {
            if (dp[city][cnt] == -1) continue;
            for (auto &next : graph[city]) 
            {
                int to = next.first;
                int score = next.second;
                if (dp[to][cnt + 1] < dp[city][cnt] + score) 
                {
                    dp[to][cnt + 1] = dp[city][cnt] + score;
                }
            }
        }
    }

    int answer = 0;
    for (int cnt = 2; cnt <= m; cnt++) 
    {
        answer = max(answer, dp[n][cnt]);
    }
    cout << answer << '\n';
    return 0;
}