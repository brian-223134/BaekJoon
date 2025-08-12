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
        // std::iota�� [begin, end) ������ 0, 1, 2... ������ ä���.
        iota(parent.begin(), parent.end(), 0);
        rank.assign(n + 1, 0);
    }

    // find ����: ��� ������ ����Ͽ� ȿ���� ����
    int find(int u)
    {
        if (u == parent[u])
        {
            return u;
        }
        return parent[u] = find(parent[u]);
    }

    // union ����: ��ũ�� �������� Ʈ���� ���� ȿ���� ����
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

    // ��� ������ ����
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
        { // ���� ���� ����
            int u;
            cin >> u;
            queries.push_back({ type, u, 0 });
            deleted[u] = true;
        }
        else 
        { // ���� Ȯ�� ����
            int u, v;
            cin >> u >> v;
            queries.push_back({ type, u, v });
        }
    }

    DisjointSet ds(N);
    // ���� ó�� ��, �������� ���� �������� ���� ����
    for (int i = 2; i <= N; ++i) 
    {
        if (!deleted[i]) 
        {
            ds.unite(i, parents[i]);
        }
    }

    // ����� ������ ����
    stack<string> results;

    // ������ �������� ó��
    for (int i = queries.size() - 1; i >= 0; --i) 
    {
        Query q = queries[i];
        if (q.type == 0)
        { // ���� �߰�(������ ����) ����
            ds.unite(q.u, parents[q.u]);
        }
        else
        { // ���� Ȯ�� ����
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

    // ����� ���� ������� ���
    while (!results.empty())
    {
        cout << results.top() << '\n';
        results.pop();
    }

    return 0;
}