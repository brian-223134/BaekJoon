#include <iostream>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

vector<pair<int, int>> tree[10001];
bool visited[10001];
int maxDist = 0;
int farthestNode;

// ���� ���, ��������� ���� �Ÿ��� ���ڷ� ����
void dfs(int node, int dist)
{
    // �̹� �湮�� ���� ����
    if (visited[node])
    {
        return;
    }
    visited[node] = true;

    // ��������� �Ÿ��� �ִ� �Ÿ����� ��ٸ� ����
    if (dist > maxDist)
    {
        maxDist = dist;
        farthestNode = node;
    }

    // ���� ��忡 ����� �ٸ� ����� Ž���� �̾
    for (auto& edge : tree[node]) 
    {
        int nextNode = edge.first;
        int nextDist = edge.second;
        dfs(nextNode, dist + nextDist);
    }
}

int main(void) 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) 
    {
        int parent, child, weight;
        cin >> parent >> child >> weight;
        tree[parent].push_back({ child, weight });
        tree[child].push_back({ parent, weight });
    }

    // 1. ������ ��(1�� ���)���� ���� �� ��带 ã��
    dfs(1, 0);

    // 2. ���� Ž���� ���� �ʱ�ȭ
    maxDist = 0;
    memset(visited, false, sizeof(visited)); // visited �迭 �ʱ�ȭ

    // 3. 1������ ���� �־��� 'farthestNode'���� �ٽ� ���� �� ��带 ã��
    // �̶��� maxDist�� Ʈ���� ������ ��
    dfs(farthestNode, 0);

    cout << maxDist << "\n";

    return 0;
}