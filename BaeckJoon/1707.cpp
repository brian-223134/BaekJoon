#include <iostream>
#include <vector>
using namespace std;

int k, v, e;
bool check;

void dfs(int node, int cur_color, vector<int>& color, vector<vector<int>>& adj) 
{
    color[node] = cur_color;
    for (int next : adj[node]) 
    {
        if (color[next] == -1) 
        {
            dfs(next, 1 - cur_color, color, adj);
            if (!check) return;
        } 
        else if (color[next] == cur_color) 
        {
            check = false;
            return;
        }
    }
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> k;
    while (k--) 
    {
        cin >> v >> e;
        check = true;
        vector<vector<int>> adj(v + 1);
        vector<int> color(v + 1, -1);
        for (int i = 0; i < e; i++) 
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (int i = 1; i <= v; i++)
        {
            if (!check) break;
            if (color[i] == -1)
            {
                dfs(i, 0, color, adj);
            }
        }
        cout << (check ? "YES" : "NO") << '\n';
    }
    return 0;
}