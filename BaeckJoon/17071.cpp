#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

// 수빈이의 초기 위치: N, 동생의 초기 위치: K
// 수빈이는 걷거나 순간이동 가능, 동생은 걷기만 가능
// 걷기: X -> X (+|-) 1 per 1 sec
// 순간이동 : X -> 2 * X per 1 sec
// 동생의 걷는 속력은 가속을 받아 변량의 +1 만큼 계속 증가

int n, k;
// visited[location][parity]: 수빈이가 특정 위치에 (0: 짝수, 1: 홀수) 시간에 도착한 가장 빠른 시간 기록
int visited[500001][2];
const int MAX = 500000;

// 좌표 크기가 크기때문에 일반적인 BFS 사용 시 timeout이 불가피하게 발생
// 수빈이가 t (mod 2 = 0) 인 시점에 x 좌표에 있을 경우 t + 2, 4, 6 ...와 같이 짝수 시간이후에 동일한 좌표 회귀 가능

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;

    if (n == k) 
    {
        cout << 0 << "\n";
        return 0;
    }

    // -1: 미방문
    memset(visited, -1, sizeof(visited));

    queue<pair<int, int>> q;
    q.push({ n, 0 }); // {위치, 시간}
    visited[n][0] = 0;

    // 1. 수빈이의 BFS 탐색 (모든 도달 가능한 시간에 대해 기록)
    while (!q.empty())
    {
        int current_pos = q.front().first;
        int current_time = q.front().second;
        q.pop();

        int next_time = current_time + 1;
        int next_parity = next_time % 2;

        // X - 1로 이동
        int next_pos_minus = current_pos - 1;
        if (next_pos_minus >= 0 && visited[next_pos_minus][next_parity] == -1) 
        {
            visited[next_pos_minus][next_parity] = next_time;
            q.push({ next_pos_minus, next_time });
        }

        // X + 1로 이동
        int next_pos_plus = current_pos + 1;
        if (next_pos_plus <= MAX && visited[next_pos_plus][next_parity] == -1) 
        {
            visited[next_pos_plus][next_parity] = next_time;
            q.push({ next_pos_plus, next_time });
        }

        // X * 2로 이동
        int next_pos_teleport = current_pos * 2;
        if (next_pos_teleport <= MAX && visited[next_pos_teleport][next_parity] == -1) 
        {
            visited[next_pos_teleport][next_parity] = next_time;
            q.push({ next_pos_teleport, next_time });
        }
    }

    // 2. 시간(t)을 흘려보내며 동생의 위치와 수빈이의 방문 기록을 비교
    int time = 0;
    while (true) 
    {
        // 현재 시간(time)에 동생의 위치 계산
        // 변량이 등차수열이기 때문에 등차 수열의 합으로 표현
        long long brother_pos = k + (long long)time * (time + 1) / 2;

        // 동생이 범위를 벗어나면 수빈이는 절대 만날 수 없음
        if (brother_pos > MAX) 
        {
            cout << -1 << "\n";
            break;
        }

        // 현재 시간의 홀짝성(parity)
        int current_parity = time % 2;

        // 수빈이가 현재 시간(time)과 같거나 그 이전에,
        // 현재 동생의 위치(brother_pos)에 같은 홀짝성(parity)으로 도착한 적이 있는지 확인
        if (visited[brother_pos][current_parity] != -1 && visited[brother_pos][current_parity] <= time)
        {
            cout << time << "\n";
            break;
        }

        time++;
    }

    return 0;
}