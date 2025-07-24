#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100001;
int from[MAX];  // 경로 추적용
bool visited[MAX];
int dist[MAX];

void print_path(int start, int end) 
{
    vector<int> path;
    for (int cur = end; cur != start; cur = from[cur])
        path.push_back(cur);
    path.push_back(start);
    reverse(path.begin(), path.end());
    cout << path.size() - 1 << "\n";
    for (int v : path) cout << v << " ";
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    queue<int> q;
    visited[n] = true;
    dist[n] = 0;
    q.push(n);

    while (!q.empty()) 
    {
        int cur = q.front(); q.pop();

        if (cur == k) 
        {
            print_path(n, k);
            return 0;
        }

        for (int next : {cur - 1, cur + 1, cur * 2}) 
        {
            if (next >= 0 && next < MAX && !visited[next]) 
            {
                visited[next] = true;
                dist[next] = dist[cur] + 1;
                from[next] = cur;
                q.push(next);
            }
        }
    }

    return 0;
}