#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int n; // �۾� ����

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    vector<int> task_time(n + 1);
    vector<vector<int>> table(n + 1);
    vector<int> in_degree(n + 1, 0); // �� �۾��� ���� ����(���� �۾� ��)

    for (int i = 1; i <= n; i++)
    {
        cin >> task_time[i]; // i�� �۾��� �ҿ� �ð�
        int num_prereqs;
        cin >> num_prereqs; // i�� �۾��� ���� �۾� ����
        for (int j = 0; j < num_prereqs; j++)
        {
            int prereq; // ���� �۾�
            cin >> prereq;
            table[prereq].push_back(i); // ���� �۾� -> ���� �۾� ���� ����
            in_degree[i]++; // ���� �۾��� ���� ���� ����
        }
    }

    // ���� ������ ���� ť�� ��� �ð� �迭
    queue<int> q;
    vector<int> result_time(n + 1, 0);

    // ���� ������ 0�� �۾�(���� ���� ������ �� �ִ� �۾�)�� ť�� ����
    for (int i = 1; i <= n; i++)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
            result_time[i] = task_time[i]; // ���� �۾��� �Ϸ� �ð��� �ڱ� �ڽ� �ð�
        }
    }

    // ���� ���� ����
    while (!q.empty())
    {
        int current_task = q.front();
        q.pop();

        // ���� �۾�(current_task)�� ���� �۾����� ���� ���� �۾���(next_task) Ȯ��
        for (int next_task : table[current_task])
        {
            // ���� �۾��� �Ϸ� �ð� ����
            // ���� �Ϸ� �ð��� (���� �۾��� �Ϸ� �ð� + ���� �۾��� �ҿ� �ð�) �� �� ū ������ ����
            result_time[next_task] = max(result_time[next_task], result_time[current_task] + task_time[next_task]);

            in_degree[next_task]--; // ���� �۾��� ���� ���� ����

            // ���� �۾��� ��� �Ϸ�Ǿ�����(���� ���� 0), ť�� ����
            if (in_degree[next_task] == 0)
            {
                q.push(next_task);
            }
        }
    }

    // ��� �۾��� ������ �ð��� �� �۾��� �Ϸ� �ð� �� �ִ�
    int max_time = 0;
    for (int i = 1; i <= n; i++)
    {
        if (result_time[i] > max_time)
        {
            max_time = result_time[i];
        }
    }
    cout << max_time << '\n';

    return 0;
}