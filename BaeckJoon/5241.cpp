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
    // n: 역 개수, k: 하이퍼 튜브가 연결하는 역 개수, m: 하이퍼 튜브 개수
    // n의 크기가 매우 크기 때문에 list나 행렬 표기는 회피하기
    // 이분 그래프 + BFS 이용하기

    vector<vector<int>> adj(n + m + 1);

    // M개의 하이퍼튜브 정보 입력받기
    for (int i = 1; i <= m; ++i) 
    {
        int tube_node = n + i; // i번째 하이퍼튜브의 노드 번호

        // K개의 역 정보 입력받기
        for (int j = 0; j < k; ++j) 
        {
            int station_node;
            cin >> station_node;

            // 양방향 간선 추가
            // 1. 역 -> 하이퍼튜브
            adj[station_node].push_back(tube_node);
            // 2. 하이퍼튜브 -> 역
            adj[tube_node].push_back(station_node);
        }
    }

    queue<pair<int, int>> q;

    vector<bool> visited(n + m + 1, false);

    q.push({ 1, 1 }); // {1번 역에서 시작, 방문한 역 개수는 1개}
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

        // 연결된 모든 인접 노드 탐색
        for (int nextNode : adj[currentNode]) 
        {
            if (!visited[nextNode]) 
            {
                visited[nextNode] = true;

                // 다음 노드가 '역'일 경우에만 방문 횟수 증가
                if (nextNode <= n) 
                {
                    q.push({ nextNode, stationCount + 1 });
                }
                // 다음 노드가 '하이퍼튜브'일 경우, 역 방문 횟수는 그대로
                else {
                    q.push({ nextNode, stationCount });
                }
            }
        }
    }

    // 큐가 비었는데 도착점에 도달하지 못했다면 경로가 없는 것
    cout << -1 << endl;
    return 0;
}