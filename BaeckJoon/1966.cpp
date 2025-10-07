#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

// 1. 현재 Queue의 가장 앞에 있는 문서의 ‘중요도’를 확인한다. (q.front().importance)
// 2. 나머지 문서들 중 현재 문서보다 중요도가 높은 문서가 하나라도 있다면, 
//    이 문서를 인쇄하지 않고 Queue의 가장 뒤에 재배치 한다. 그렇지 않다면 바로 인쇄를 한다.
// 우선순위 큐를 이용하지 않고 vector<int>에 보관할 경우 -> 이 경우 sort를 매번 진행해야 함. -> time out
// 결국 우선순위 큐를 사용해야 함

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        queue<pair<int, int>> q;          // (인덱스, 중요도)
        priority_queue<int> pq;           // 현재 큐에서 가장 높은 중요도 추적

        for (int i = 0; i < n; i++)
        {
            int priority;
            cin >> priority;
            q.push({ i, priority });
            pq.push(priority);
        }

        int printed = 0;
        while (!q.empty())
        {
            auto cur = q.front();

            // 현재 문서가 가장 높은 중요도라면 인쇄
            if (cur.second == pq.top())
            {
                q.pop();
                pq.pop();
                ++printed;

                if (cur.first == m)
                {
                    cout << printed << '\n';
                    break;
                }
            }
            else
            {
                // 더 높은 중요도가 있으면 뒤로 보냄
                q.pop();
                q.push(cur);
            }
        }
    }

    return 0;
}