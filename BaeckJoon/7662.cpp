#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int query = 0;
        cin >> query;

        // �ִ�/�ּ� ���� lazy deletion�� ���� �湮 �迭
        priority_queue<pair<long long,int>> maxpq;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> minpq;
        vector<bool> alive(query, false); // ���� �׸��� ��ȿ��
        int id = 0; // �� ���Կ� �ο��� ���� id

        char q_t;
        long long num;
        for (int i = 0; i < query; i++)
        {
            cin >> q_t >> num;

            if (q_t == 'I')
            {
                maxpq.emplace(num, id);
                minpq.emplace(num, id);
                alive[id] = true;
                ++id;
            }
            else if (q_t == 'D')
            {
                if (num == 1)
                {
                    // �ִ밪 ����
                    while (!maxpq.empty() && !alive[maxpq.top().second]) maxpq.pop();
                    if (!maxpq.empty())
                    {
                        alive[maxpq.top().second] = false;
                        maxpq.pop();
                    }
                }
                else if (num == -1)
                {
                    // �ּҰ� ����
                    while (!minpq.empty() && !alive[minpq.top().second]) minpq.pop();
                    if (!minpq.empty())
                    {
                        alive[minpq.top().second] = false;
                        minpq.pop();
                    }
                }
            }
        }

        while (!maxpq.empty() && !alive[maxpq.top().second]) maxpq.pop();
        while (!minpq.empty() && !alive[minpq.top().second]) minpq.pop();

        if (maxpq.empty() || minpq.empty())
        {
            cout << "EMPTY\n";
        }
        else
        {
            cout << maxpq.top().first << ' ' << minpq.top().first << '\n';
        }
    }
    return 0;
}