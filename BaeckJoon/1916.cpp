#include<iostream>
#include<queue>
#include<vector>
#include <limits>


using namespace std;

const int INF = numeric_limits<int>::max();

int n; // 도시 개수
int m; // 버스 개수

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> m; // 간선의 개수

	vector<vector<pair<int, int>>> graph(n + 1); // 1-indexed

	for (int i = 0; i < m; i++) 
	{
		int u, v, cost; // u: 시작 노드, v: 도착 노드, cost: 간선의 비용
		cin >> u >> v >> cost;
		graph[u].push_back({ v, cost });
	}

	int start, end;
	cin >> start >> end; // 시작 지점 -> 도착 지점

	// 다익스트라 알고리즘
	vector<int> dist(n + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	dist[start] = 0;
	pq.push({ 0, start }); // cost, 시작지점

	while (!pq.empty()) 
	{
		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (dist[now] < cost) continue;

		for (const auto& edge : graph[now]) {
			int next = edge.first;
			int weight = edge.second;

			if (dist[next] > cost + weight) {
				dist[next] = cost + weight;
				pq.push({ dist[next], next });
			}
		}
	}

	cout << dist[end];

	return 0;
}