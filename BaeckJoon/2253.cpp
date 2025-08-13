#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
bool cant_cross[10001];
bool visited[10001][200]; // [위치][직전 점프 길이]

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        cant_cross[temp] = true;
    }

    queue<pair<int, int> > q; // {좌표, 직전 점프 길이}
    q.push(make_pair(1, 0));
    visited[1][0] = true;

    int step = 0;
    while (!q.empty())
    {
        int sz = q.size();
        step++;
        for (int i = 0; i < sz; i++)
        {
            pair<int, int> cur = q.front(); q.pop();
            int pos = cur.first;
            int jump = cur.second;
            for (int d = -1; d <= 1; d++)
            {
                int njump = jump + d;
                if (njump < 1) continue;
                int npos = pos + njump;
                if (npos > n) continue;
                if (cant_cross[npos]) continue;
                if (visited[npos][njump]) continue;
                if (npos == n)
                {
                    cout << step << '\n';
                    return 0;
                }
                visited[npos][njump] = true;
                q.push(make_pair(npos, njump));
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}