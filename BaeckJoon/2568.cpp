#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Wire {
    int a, b;
} Wire;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<Wire> wires(N);
    for (int i = 0; i < N; ++i) 
    {
        cin >> wires[i].a >> wires[i].b;
    }

    // A 기준 정렬
    sort(wires.begin(), wires.end(), [](const Wire& w1, const Wire& w2) {
        return w1.a < w2.a;
    });

    // LIS 구하기
    vector<int> dp, idx(N), prev(N, -1);
    for (int i = 0; i < N; ++i)
    {
        int b = wires[i].b;
        auto it = lower_bound(dp.begin(), dp.end(), b);
        int pos = it - dp.begin();
        if (it == dp.end())
        {
            dp.push_back(b);
        } 
        else 
        {
            *it = b;
        }
        
        idx[i] = pos;

        if (pos > 0)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                if (idx[j] == pos - 1 && wires[j].b < b)
                {
                    prev[i] = j;
                    break;
                }
            }
        }
    }

    // LIS에 포함된 인덱스 추적
    int lis_len = dp.size();
    vector<bool> in_lis(N, false);
    int cur = -1;
    for (int i = N - 1; i >= 0; --i)
    {
        if (idx[i] == lis_len - 1)
        {
            cur = i;
            break;
        }
    }
    while (cur != -1)
    {
        in_lis[cur] = true;
        cur = prev[cur];
    }

    cout << N - lis_len << '\n';
    for (int i = 0; i < N; ++i) 
    {
        if (!in_lis[i]) cout << wires[i].a << '\n';
    }
    return 0;
}