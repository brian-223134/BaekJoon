#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

class DisjointSet 
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int n) 
    {
        parent.resize(n + 1);
        // std::iota는 [begin, end) 범위를 0, 1, 2... 순서로 채운다.
        iota(parent.begin(), parent.end(), 0);
        rank.assign(n + 1, 0);
    }

    // find 연산: 경로 압축을 사용하여 효율성 증진
    int find(int u)
    {
        if (u == parent[u])
        {
            return u;
        }
        return parent[u] = find(parent[u]);
    }

    // union 연산: 랭크를 기준으로 트리를 합쳐 효율성 증진
    void unite(int u, int v) 
    {
        u = find(u);
        v = find(v);
        if (u != v) 
        {
            if (rank[u] < rank[v]) 
            {
                std::swap(u, v);
            }
            parent[v] = u;
            if (rank[u] == rank[v]) 
            {
                rank[u]++;
            }
        }
    }
};

int main(void) 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    std::vector<int> parents(N + 1);
    for (int i = 2; i <= N; ++i)
    {
        cin >> parents[i];
    }

    // 모든 쿼리를 저장
    struct Query 
    {
        int type;
        int u;
        int v;
    };
    vector<Query> queries;
    vector<bool> deleted(N + 1, false);

    for (int i = 0; i < N - 1 + Q; ++i) 
    {
        int type;
        cin >> type;
        if (type == 0) 
        { // 간선 삭제 쿼리
            int u;
            cin >> u;
            queries.push_back({ type, u, 0 });
            deleted[u] = true;
        }
        else 
        { // 연결 확인 쿼리
            int u, v;
            cin >> u >> v;
            queries.push_back({ type, u, v });
        }
    }

    DisjointSet ds(N);
    // 쿼리 처리 전, 삭제되지 않은 간선들을 먼저 연결
    for (int i = 2; i <= N; ++i) 
    {
        if (!deleted[i]) 
        {
            ds.unite(i, parents[i]);
        }
    }

    // 결과를 저장할 스택
    stack<string> results;

    // 쿼리를 역순으로 처리
    for (int i = queries.size() - 1; i >= 0; --i) 
    {
        Query q = queries[i];
        if (q.type == 0)
        { // 간선 추가(원래는 삭제) 쿼리
            ds.unite(q.u, parents[q.u]);
        }
        else
        { // 연결 확인 쿼리
            if (ds.find(q.u) == ds.find(q.v)) 
            {
                results.push("YES");
            }
            else
            {
                results.push("NO");
            }
        }
    }

    // 결과를 원래 순서대로 출력
    while (!results.empty())
    {
        cout << results.top() << '\n';
        results.pop();
    }

    return 0;
}