#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

// �������� �ʱ� ��ġ: N, ������ �ʱ� ��ġ: K
// �����̴� �Ȱų� �����̵� ����, ������ �ȱ⸸ ����
// �ȱ�: X -> X (+|-) 1 per 1 sec
// �����̵� : X -> 2 * X per 1 sec
// ������ �ȴ� �ӷ��� ������ �޾� ������ +1 ��ŭ ��� ����

int n, k;
// visited[location][parity]: �����̰� Ư�� ��ġ�� (0: ¦��, 1: Ȧ��) �ð��� ������ ���� ���� �ð� ���
int visited[500001][2];
const int MAX = 500000;

// ��ǥ ũ�Ⱑ ũ�⶧���� �Ϲ����� BFS ��� �� timeout�� �Ұ����ϰ� �߻�
// �����̰� t (mod 2 = 0) �� ������ x ��ǥ�� ���� ��� t + 2, 4, 6 ...�� ���� ¦�� �ð����Ŀ� ������ ��ǥ ȸ�� ����

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

    // -1: �̹湮
    memset(visited, -1, sizeof(visited));

    queue<pair<int, int>> q;
    q.push({ n, 0 }); // {��ġ, �ð�}
    visited[n][0] = 0;

    // 1. �������� BFS Ž�� (��� ���� ������ �ð��� ���� ���)
    while (!q.empty())
    {
        int current_pos = q.front().first;
        int current_time = q.front().second;
        q.pop();

        int next_time = current_time + 1;
        int next_parity = next_time % 2;

        // X - 1�� �̵�
        int next_pos_minus = current_pos - 1;
        if (next_pos_minus >= 0 && visited[next_pos_minus][next_parity] == -1) 
        {
            visited[next_pos_minus][next_parity] = next_time;
            q.push({ next_pos_minus, next_time });
        }

        // X + 1�� �̵�
        int next_pos_plus = current_pos + 1;
        if (next_pos_plus <= MAX && visited[next_pos_plus][next_parity] == -1) 
        {
            visited[next_pos_plus][next_parity] = next_time;
            q.push({ next_pos_plus, next_time });
        }

        // X * 2�� �̵�
        int next_pos_teleport = current_pos * 2;
        if (next_pos_teleport <= MAX && visited[next_pos_teleport][next_parity] == -1) 
        {
            visited[next_pos_teleport][next_parity] = next_time;
            q.push({ next_pos_teleport, next_time });
        }
    }

    // 2. �ð�(t)�� ��������� ������ ��ġ�� �������� �湮 ����� ��
    int time = 0;
    while (true) 
    {
        // ���� �ð�(time)�� ������ ��ġ ���
        // ������ ���������̱� ������ ���� ������ ������ ǥ��
        long long brother_pos = k + (long long)time * (time + 1) / 2;

        // ������ ������ ����� �����̴� ���� ���� �� ����
        if (brother_pos > MAX) 
        {
            cout << -1 << "\n";
            break;
        }

        // ���� �ð��� Ȧ¦��(parity)
        int current_parity = time % 2;

        // �����̰� ���� �ð�(time)�� ���ų� �� ������,
        // ���� ������ ��ġ(brother_pos)�� ���� Ȧ¦��(parity)���� ������ ���� �ִ��� Ȯ��
        if (visited[brother_pos][current_parity] != -1 && visited[brother_pos][current_parity] <= time)
        {
            cout << time << "\n";
            break;
        }

        time++;
    }

    return 0;
}