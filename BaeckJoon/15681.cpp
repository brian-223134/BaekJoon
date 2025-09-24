#include <iostream>
#include <vector>
using namespace std;

int n, r, q;
vector<int> tree[100001];
int subtree_size[100001];

void dfs(int node, int parent) 
{
    subtree_size[node] = 1; // 자기 자신 포함
    for (int next : tree[node]) 
    {
        if (next != parent) 
        {
            dfs(next, node);
            subtree_size[node] += subtree_size[next];
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> r >> q;
    for (int i = 0; i < n - 1; i++) 
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(r, 0);

    for (int i = 0; i < q; i++) 
    {
        int query;
        cin >> query;
        cout << subtree_size[query] << '\n';
    }

    return 0;
}