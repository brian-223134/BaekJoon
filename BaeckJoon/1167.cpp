#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 100001;

// pair<int, int>�� {����� ����, ���� ����ġ}�� �ǹ�
vector<pair<int, int>> adj[MAX];

// �湮 ���ο� �Ÿ��� ������ �迭
bool visited[MAX];
int dist[MAX];

// ������ ����
int V;

/**
 * @brief �ʺ� �켱 Ž��(BFS)�� �����Ͽ� ���� ���κ��� �� �������� �Ÿ��� ���
 * @param startNode Ž���� ������ ���
 */
void bfs(int startNode) 
{
    // �� Ž������ �湮 �迭�� �Ÿ� �迭�� �ʱ�ȭ�մϴ�.
    memset(visited, false, sizeof(visited));
    memset(dist, 0, sizeof(dist));

    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) 
    {
        int currentNode = q.front();
        q.pop();

        // ���� ���� ����� ��� ������ Ȯ��
        for (auto& edge : adj[currentNode]) 
        {
            int nextNode = edge.first;
            int weight = edge.second;

            // ���� �湮���� ���� �����
            if (!visited[nextNode]) 
            {
                visited[nextNode] = true;
                // ���� �������� �Ÿ��� ���� ������ ����ġ�� ����
                dist[nextNode] = dist[currentNode] + weight;
                q.push(nextNode);
            }
        }
    }
}

int main(void) 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> V;

    // Ʈ�� ���� �Է¹޾� ���� ����Ʈ ����
    for (int i = 0; i < V; ++i) 
    {
        int u;
        cin >> u;
        while (true) 
        {
            int v, w;
            cin >> v;
            if (v == -1) break; // �Է� ���� ����
            cin >> w;
            adj[u].push_back({ v, w });
        }
    }

    // 1. ������ ����(1��)���� ���� �� ������ ã��
    bfs(1);

    int farthestNode = 1; // ���� �� ������ ������ ����
    for (int i = 2; i <= V; ++i) 
    {
        if (dist[i] > dist[farthestNode]) 
        {
            farthestNode = i;
        }
    }

    // 2. ������ ã�� 'farthestNode'���� �ٽ� ���� �� ���������� �Ÿ��� ����
    // �� �Ÿ��� �ٷ� Ʈ���� ����
    bfs(farthestNode);

    int diameter = 0;
    for (int i = 1; i <= V; ++i) 
    {
        if (dist[i] > diameter) 
        {
            diameter = dist[i];
        }
    }

    cout << diameter << "\n";

    return 0;
}