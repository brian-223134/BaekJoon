#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<bool> visited;
stack<int> st;

void dfs(int node) 
{
    visited[node] = true;
    for (int next : graph[node]) 
    {
        if (!visited[next]) 
        {
            dfs(next);
        }
    }
    st.push(node); // ��� ���� ��� Ž�� �� push, ��������
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    graph.resize(n + 1);
    visited.assign(n + 1, false);

    for (int i = 0; i < m; i++) 
    {
        int a, b;
        cin >> a >> b;       // a�� b���� �տ�
        graph[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) 
    {
        if (!visited[i]) dfs(i);
    }

    while (!st.empty()) 
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}