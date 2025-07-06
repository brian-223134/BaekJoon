#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int n, m;
vector<vector<int>> _map;
vector<int> order;
int cnt = 1;

void dfs(int node)
{
    order[node] = cnt++;
    for (int next : _map[node]) {
        if (order[next] == 0) {
            dfs(next);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int start;
    cin >> n >> m >> start;

    _map.resize(n + 1);
    order.resize(n + 1, 0);

    int s, e;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> e;
        _map[s].push_back(e);
        _map[e].push_back(s); // ����� �׷���
    }

    // ���� ���� ����
    for (int i = 1; i <= n; i++) {
        sort(_map[i].begin(), _map[i].end());
    }

    dfs(start);

    for (int i = 1; i <= n; i++) {
        cout << order[i] << '\n';
    }

    return 0;
}