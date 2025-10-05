#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

struct Edge {
    int u, v;
    int w;
};

// 유니온 파인드 구조, 구조체에 함수 선언이 가능함...
// 클래스 대신 구조체 재사용하는 것이 좋을지도
struct DSU {
    vector<int> p, sz;
    DSU(int n = 0) { init(n); }
    void init(int n)
    {
        p.resize(n);
        sz.assign(n, 1);
        for (int i = 0; i < n; ++i) p[i] = i;
    }
    int find(int x)
    {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    bool unite(int a, int b) 
    {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<pair<int,int>> xs(n), ys(n), zs(n);
    for (int i = 0; i < n; ++i) 
    {
        int x, y, z;
        cin >> x >> y >> z;
        xs[i] = {x, i};
        ys[i] = {y, i};
        zs[i] = {z, i};
    }

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    sort(zs.begin(), zs.end());

    vector<Edge> edges;
    edges.reserve(max(0, 3 * (n - 1)));

    for (int i = 1; i < n; ++i) 
    {
        edges.push_back({ xs[i-1].second, xs[i].second, abs(xs[i].first - xs[i-1].first) });
        edges.push_back({ ys[i-1].second, ys[i].second, abs(ys[i].first - ys[i-1].first) });
        edges.push_back({ zs[i-1].second, zs[i].second, abs(zs[i].first - zs[i-1].first) });
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b){
        return a.w < b.w;
    });

    // 크루스칼을 이용하면 된다. 간선 비용에 절댓값이 붙기에 음의 간선이 없음
    DSU dsu(n);
    long long ans = 0;
    int used = 0;
    for (const auto& e : edges) 
    {
        if (dsu.unite(e.u, e.v)) 
        {
            ans += e.w;
            if (++used == n - 1) break;
        }
    }

    cout << ans << '\n';
    return 0;
}