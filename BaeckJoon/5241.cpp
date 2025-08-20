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

    int n, k, m;
    cin >> n >> k >> m;
    // n: �� ����, k: ������ Ʃ�갡 �����ϴ� �� ����, m: ������ Ʃ�� ����
    // n�� ũ�Ⱑ �ſ� ũ�� ������ list�� ��� ǥ��� ȸ���ϱ�
    // �̺� �׷��� + BFS �̿��ϱ�

    vector<vector<int>> adj(n + m + 1);

    // M���� ������Ʃ�� ���� �Է¹ޱ�
    for (int i = 1; i <= m; ++i) 
    {
        int tube_node = n + i; // i��° ������Ʃ���� ��� ��ȣ

        // K���� �� ���� �Է¹ޱ�
        for (int j = 0; j < k; ++j) 
        {
            int station_node;
            cin >> station_node;

            // ����� ���� �߰�
            // 1. �� -> ������Ʃ��
            adj[station_node].push_back(tube_node);
            // 2. ������Ʃ�� -> ��
            adj[tube_node].push_back(station_node);
        }
    }

    queue<pair<int, int>> q;

    vector<bool> visited(n + m + 1, false);

    q.push({ 1, 1 }); // {1�� ������ ����, �湮�� �� ������ 1��}
    visited[1] = true;

    while (!q.empty()) 
    {
        int currentNode = q.front().first;
        int stationCount = q.front().second;
        q.pop();

        if (currentNode == n) 
        {
            cout << stationCount << endl;
            return 0;
        }

        // ����� ��� ���� ��� Ž��
        for (int nextNode : adj[currentNode]) 
        {
            if (!visited[nextNode]) 
            {
                visited[nextNode] = true;

                // ���� ��尡 '��'�� ��쿡�� �湮 Ƚ�� ����
                if (nextNode <= n) 
                {
                    q.push({ nextNode, stationCount + 1 });
                }
                // ���� ��尡 '������Ʃ��'�� ���, �� �湮 Ƚ���� �״��
                else {
                    q.push({ nextNode, stationCount });
                }
            }
        }
    }

    // ť�� ����µ� �������� �������� ���ߴٸ� ��ΰ� ���� ��
    cout << -1 << endl;
    return 0;
}