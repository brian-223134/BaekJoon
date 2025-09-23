#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int n; // 작업 개수

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    vector<int> task_time(n + 1);
    vector<vector<int>> table(n + 1);
    vector<int> in_degree(n + 1, 0); // 각 작업의 진입 차수(선행 작업 수)

    for (int i = 1; i <= n; i++)
    {
        cin >> task_time[i]; // i번 작업의 소요 시간
        int num_prereqs;
        cin >> num_prereqs; // i번 작업의 선행 작업 개수
        for (int j = 0; j < num_prereqs; j++)
        {
            int prereq; // 선행 작업
            cin >> prereq;
            table[prereq].push_back(i); // 선행 작업 -> 현재 작업 간선 연결
            in_degree[i]++; // 현재 작업의 진입 차수 증가
        }
    }

    // 위상 정렬을 위한 큐와 결과 시간 배열
    queue<int> q;
    vector<int> result_time(n + 1, 0);

    // 진입 차수가 0인 작업(가장 먼저 시작할 수 있는 작업)을 큐에 삽입
    for (int i = 1; i <= n; i++)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
            result_time[i] = task_time[i]; // 시작 작업의 완료 시간은 자기 자신 시간
        }
    }

    // 위상 정렬 진행
    while (!q.empty())
    {
        int current_task = q.front();
        q.pop();

        // 현재 작업(current_task)을 선행 작업으로 갖는 다음 작업들(next_task) 확인
        for (int next_task : table[current_task])
        {
            // 다음 작업의 완료 시간 갱신
            // 기존 완료 시간과 (현재 작업의 완료 시간 + 다음 작업의 소요 시간) 중 더 큰 값으로 갱신
            result_time[next_task] = max(result_time[next_task], result_time[current_task] + task_time[next_task]);

            in_degree[next_task]--; // 다음 작업의 진입 차수 감소

            // 선행 작업이 모두 완료되었으면(진입 차수 0), 큐에 삽입
            if (in_degree[next_task] == 0)
            {
                q.push(next_task);
            }
        }
    }

    // 모든 작업이 끝나는 시간은 각 작업의 완료 시간 중 최댓값
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