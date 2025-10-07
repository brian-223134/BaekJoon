#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

// 1. ���� Queue�� ���� �տ� �ִ� ������ ���߿䵵���� Ȯ���Ѵ�. (q.front().importance)
// 2. ������ ������ �� ���� �������� �߿䵵�� ���� ������ �ϳ��� �ִٸ�, 
//    �� ������ �μ����� �ʰ� Queue�� ���� �ڿ� ���ġ �Ѵ�. �׷��� �ʴٸ� �ٷ� �μ⸦ �Ѵ�.
// �켱���� ť�� �̿����� �ʰ� vector<int>�� ������ ��� -> �� ��� sort�� �Ź� �����ؾ� ��. -> time out
// �ᱹ �켱���� ť�� ����ؾ� ��

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

        queue<pair<int, int>> q;          // (�ε���, �߿䵵)
        priority_queue<int> pq;           // ���� ť���� ���� ���� �߿䵵 ����

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

            // ���� ������ ���� ���� �߿䵵��� �μ�
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
                // �� ���� �߿䵵�� ������ �ڷ� ����
                q.pop();
                q.push(cur);
            }
        }
    }

    return 0;
}