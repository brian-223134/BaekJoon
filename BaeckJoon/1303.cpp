#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

char p[100][100];
bool vis[100][100];
int n, m;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

bool OOB(int y, int x)
{
    return y >= n || y < 0 || x >= m || x < 0;
}

int dfs_count(int sy, int sx)
{
    char color = p[sy][sx];
    int cnt = 0;
    stack<pair<int,int>> st;
    st.push(make_pair(sy, sx));
    vis[sy][sx] = true;

    while (!st.empty())
    {
        pair<int,int> cur = st.top();
        st.pop();
        int y = cur.first;
        int x = cur.second;
        cnt++;

        for (int dir = 0; dir < 4; dir++)
        {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (OOB(ny, nx)) continue;
            if (vis[ny][nx]) continue;
            if (p[ny][nx] != color) continue;
            vis[ny][nx] = true;
            st.push(make_pair(ny, nx));
        }
    }
    return cnt;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> m >> n;

    string temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        for (int j = 0; j < m; j++)
        {
            p[i][j] = temp[j];
        }
    }

    memset(vis, 0, sizeof(vis));
    int wsum = 0;
    int bsum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j]) continue;
            int sz = dfs_count(i, j);
            if (p[i][j] == 'W') wsum += sz * sz;
            else bsum += sz * sz;
        }
    }

    cout << wsum << " " << bsum << "\n";
    return 0;
}