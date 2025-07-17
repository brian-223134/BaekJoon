#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int visited[100001]; // �ִ� k�� 100000�̹Ƿ� +1
int dist[100001];    // �� ��ġ���� �����ϴ� �� �ɸ��� �ð�

int bfs() 
{
    queue<int> q;
    q.push(n);
    visited[n] = 1; // �湮 ǥ�� (�ð��� 0���� ���� ������ ���� ����)
    dist[n] = 0;

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        if (cur == k) return dist[cur]; // ���������� �ð� ��ȯ

        for (int next : {cur - 1, cur + 1, cur * 2}) {
            if (next < 0 || next > 100000) continue;
            if (!visited[next]) {
                visited[next] = 1;
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    cout << bfs();
    return 0;
}