#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 100001;

// pair<int, int>는 {연결된 정점, 간선 가중치}를 의미
vector<pair<int, int>> adj[MAX];

// 방문 여부와 거리를 저장할 배열
bool visited[MAX];
int dist[MAX];

// 정점의 개수
int V;

/**
 * @brief 너비 우선 탐색(BFS)을 수행하여 시작 노드로부터 각 노드까지의 거리를 계산
 * @param startNode 탐색을 시작할 노드
 */
void bfs(int startNode) 
{
    // 매 탐색마다 방문 배열과 거리 배열을 초기화합니다.
    memset(visited, false, sizeof(visited));
    memset(dist, 0, sizeof(dist));

    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) 
    {
        int currentNode = q.front();
        q.pop();

        // 현재 노드와 연결된 모든 간선을 확인
        for (auto& edge : adj[currentNode]) 
        {
            int nextNode = edge.first;
            int weight = edge.second;

            // 아직 방문하지 않은 노드라면
            if (!visited[nextNode]) 
            {
                visited[nextNode] = true;
                // 이전 노드까지의 거리에 현재 간선의 가중치를 더함
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

    // 트리 정보 입력받아 인접 리스트 구성
    for (int i = 0; i < V; ++i) 
    {
        int u;
        cin >> u;
        while (true) 
        {
            int v, w;
            cin >> v;
            if (v == -1) break; // 입력 종료 조건
            cin >> w;
            adj[u].push_back({ v, w });
        }
    }

    // 1. 임의의 정점(1번)에서 가장 먼 정점을 찾기
    bfs(1);

    int farthestNode = 1; // 가장 먼 정점을 저장할 변수
    for (int i = 2; i <= V; ++i) 
    {
        if (dist[i] > dist[farthestNode]) 
        {
            farthestNode = i;
        }
    }

    // 2. 위에서 찾은 'farthestNode'에서 다시 가장 먼 정점까지의 거리를 구함
    // 이 거리가 바로 트리의 지름
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