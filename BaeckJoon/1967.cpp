#include <iostream>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

vector<pair<int, int>> tree[10001];
bool visited[10001];
int maxDist = 0;
int farthestNode;

// 현재 노드, 현재까지의 누적 거리를 인자로 받음
void dfs(int node, int dist)
{
    // 이미 방문한 노드면 무시
    if (visited[node])
    {
        return;
    }
    visited[node] = true;

    // 현재까지의 거리가 최대 거리보다 길다면 갱신
    if (dist > maxDist)
    {
        maxDist = dist;
        farthestNode = node;
    }

    // 현재 노드에 연결된 다른 노드들로 탐색을 이어감
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

    // 1. 임의의 점(1번 노드)에서 가장 먼 노드를 찾음
    dfs(1, 0);

    // 2. 다음 탐색을 위해 초기화
    maxDist = 0;
    memset(visited, false, sizeof(visited)); // visited 배열 초기화

    // 3. 1번에서 가장 멀었던 'farthestNode'에서 다시 가장 먼 노드를 찾음
    // 이때의 maxDist가 트리의 지름이 됨
    dfs(farthestNode, 0);

    cout << maxDist << "\n";

    return 0;
}