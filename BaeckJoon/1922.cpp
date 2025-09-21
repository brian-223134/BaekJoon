#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int n, m;
typedef struct edges
{
    int u;
    int v;
    int w;
    bool operator<(const edges& other)
    {
        return w < other.w;
    }
} edges;

int find_parent(int x, vector<int>& parents)
{
    if (parents[x] == x)
    {
        return x;
    }
    return parents[x] = find_parent(parents[x], parents);
}

void unite(int a, int b, vector<int>& parents)
{
    a = find_parent(a, parents);
    b = find_parent(b, parents);
    if (a < b)
    {
        parents[b] = a;
    }
    else
    {
        parents[a] = b;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    cin >> m;

    vector<int> parents(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        parents[i] = i;
    }

    vector<edges> lines(m);
    for (int i = 0; i < m; i++)
    {
        cin >> lines[i].u >> lines[i].v >> lines[i].w;
    }

    sort(lines.begin(), lines.end());

    int total = 0;
    int e_cnt = 0;
    for (const auto& e : lines)
    {
        if (find_parent(e.u, parents) != find_parent(e.v, parents))
        {
            unite(e.u, e.v, parents);
            total += e.w;
            e_cnt++;

            if (e_cnt == n - 1)
            {
                cout << total;
                return 0;
            }
        }
    }

    cout << -1;
    return 0;
}