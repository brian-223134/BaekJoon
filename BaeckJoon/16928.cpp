#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int n, m; // n: 사다리 개수, m: 뱀 개수
// 사다리: {x, y}: x에 도착시 y로 이동
// 뱀: {u, v}: u에 도착시 v로 이동

struct portal
{
    int a, b;
    int type; // 0: 사다리, 1: 뱀
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    vector<portal> gate(n + m);

    for (int i = 0; i < n; i++)
    {
        cin >> gate[i].a >> gate[i].b;
        gate[i].type = 0;
    }

    for (int i = n; i < n + m; i++)
    {
        cin >> gate[i].a >> gate[i].b;
        gate[i].type = 1;
    }

    // 칸별 워프(사다리/뱀) 매핑
    int warp[101];
    memset(warp, 0, sizeof(warp));
    for (int i = 0; i < n + m; ++i)
    {
        warp[gate[i].a] = gate[i].b;
    }

    // BFS: (현재 위치, 주사위 굴린 횟수)
    queue<pair<int, int>> q;
    bool visited[101];
    memset(visited, false, sizeof(visited));

    q.emplace(1, 0);
    visited[1] = true;

    while (!q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop();
        int pos = cur.first;
        int cnt = cur.second;

        if (pos == 100)
        {
            cout << cnt << '\n';
            return 0;
        }

        for (int d = 1; d <= 6; ++d)
        {
            int nxt = pos + d;
            if (nxt > 100) continue;

            // 사다리/뱀 이동 적용
            if (warp[nxt] != 0) nxt = warp[nxt];

            if (!visited[nxt])
            {
                visited[nxt] = true;
                q.emplace(nxt, cnt + 1);
            }
        }
    }

    // 도달 불가한 경우(문제 특성상 거의 없음)
    cout << -1 << '\n';
    return 0;
}