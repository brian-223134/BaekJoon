#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

// u-v를 잇는 가중치 w의 간선(길) 정보
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

    int m, n; // m: 집의 수, n: 길의 수
    while (cin >> m >> n && (m != 0 || n != 0))
    {
        vector<edges> roads;
        long long total_cost = 0;

        for (int i = 0; i < n; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            roads.push_back({ u, v, w });
            total_cost += w;
        }

        sort(roads.begin(), roads.end());

        vector<int> parents(m);
        for (int i = 0; i < m; i++)
        {
            parents[i] = i;
        }

        long long mst_cost = 0;
        int edges_count = 0;

        for (const auto& e : roads)
        {
            if (find_parent(e.u, parents) != find_parent(e.v, parents))
            {
                unite(e.u, e.v, parents);
                mst_cost += e.w;
                if (++edges_count == m - 1) break;
            }
        }

        cout << total_cost - mst_cost << '\n';
    }

    return 0;
}