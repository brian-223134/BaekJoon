#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int n, m; // n: ��ٸ� ����, m: �� ����
// ��ٸ�: {x, y}: x�� ������ y�� �̵�
// ��: {u, v}: u�� ������ v�� �̵�

struct portal
{
    int a, b;
    int type; // 0: ��ٸ�, 1: ��
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

    // ĭ�� ����(��ٸ�/��) ����
    int warp[101];
    memset(warp, 0, sizeof(warp));
    for (int i = 0; i < n + m; ++i)
    {
        warp[gate[i].a] = gate[i].b;
    }

    // BFS: (���� ��ġ, �ֻ��� ���� Ƚ��)
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

            // ��ٸ�/�� �̵� ����
            if (warp[nxt] != 0) nxt = warp[nxt];

            if (!visited[nxt])
            {
                visited[nxt] = true;
                q.emplace(nxt, cnt + 1);
            }
        }
    }

    // ���� �Ұ��� ���(���� Ư���� ���� ����)
    cout << -1 << '\n';
    return 0;
}