#include <iostream>
#include <vector>
#include <deque>
#include <climits>

using namespace std;

int n, k;
vector<int> road(100001, INT_MAX);

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;
    deque<int> dq;
    dq.push_back(n);
    road[n] = 0;

    while (!dq.empty()) 
    {
        int cur = dq.front(); dq.pop_front();

        if (cur == k) 
        {
            cout << road[cur];
            return 0;
        }

        // 순간이동 (0초)
        if (cur * 2 <= 100000 && road[cur * 2] > road[cur]) 
        {
            road[cur * 2] = road[cur];
            dq.push_front(cur * 2);
        }

        // 뒤로 걷기 (1초)
        if (cur - 1 >= 0 && road[cur - 1] > road[cur] + 1) 
        {
            road[cur - 1] = road[cur] + 1;
            dq.push_back(cur - 1);
        }

        // 앞으로 걷기 (1초)
        if (cur + 1 <= 100000 && road[cur + 1] > road[cur] + 1) 
        {
            road[cur + 1] = road[cur] + 1;
            dq.push_back(cur + 1);
        }
    }

    return 0;
}