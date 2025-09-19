#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

typedef struct edge
{
    int u;
    int v;
    int w;

    // 간선의 가중치를 기준으로 오름차순으로 정렬
    bool operator<(const edge& other) const
    {
        return w < other.w;
    }
}edge;

int find_parent(int x, vector<int>& parents) 
{
    if (parents[x] == x) 
    {
        return x;
    }
    // 경로 압축(Path Compression) 최적화
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

    int n, m;
    cin >> n >> m;

    vector<edge> roads(m);
    vector<int> parents(n + 1);

    for (int i = 0; i < m; i++)
    {
        cin >> roads[i].u >> roads[i].v >> roads[i].w;
    }

    for (int i = 1; i <= n; i++)
    {
        parents[i] = i;
    }

    sort(roads.begin(), roads.end());

    int total = 0;
    int max_w = 0;
    int e_cnt = 0;
    for (const auto& e : roads)
    {
        if (find_parent(e.u, parents) != find_parent(e.v, parents))
        {
            unite(e.u, e.v, parents);
            total += e.w;
            max_w = e.w;
            e_cnt++;

            if (e_cnt == n - 1)
            {
                break;
            }
        }
    }

    cout << total - max_w;

    return 0;
}