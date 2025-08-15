#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int graph[100][100];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = (i == j ? 0 : INF);

    for (int i = 0; i < m; i++)
    {
        int heavy, light;
        cin >> heavy >> light;
        graph[heavy][light] = 1;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

    int ans = 0;
    int half = (n - 1) / 2;
    for (int i = 1; i <= n; i++)
    {
        int heavy_cnt = 0, light_cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (graph[i][j] != INF && i != j) light_cnt++; // i가 j보다 무거움
            if (graph[j][i] != INF && i != j) heavy_cnt++; // i가 j보다 가벼움
        }
        if (heavy_cnt > half || light_cnt > half) ans++;
    }

    cout << ans;
    return 0;
}