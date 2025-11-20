#include <iostream>
#include <algorithm>

using namespace std;

int n, m, b;
int _map[500][500];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> b;
    int minH = 256, maxH = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> _map[i][j];
            minH = min(minH, _map[i][j]);
            maxH = max(maxH, _map[i][j]);
        }
    }

    int bestTime = 1e9;
    int bestHeight = -1;

    for (int h = minH; h <= maxH; ++h)
    {
        int time = 0;
        int inventory = b;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                int cur = _map[i][j];
                if (cur > h)
                {
                    int diff = cur - h;
                    time += diff * 2;     // 제거
                    inventory += diff;
                }
                else if (cur < h)
                {
                    int diff = h - cur;
                    time += diff;         // 채우기
                    inventory -= diff;
                }
            }
        }

        if (inventory < 0) continue; // 블록 부족

        if (time < bestTime || (time == bestTime && h > bestHeight))
        {
            bestTime = time;
            bestHeight = h;
        }
    }

    cout << bestTime << ' ' << bestHeight << '\n';
    return 0;
}