#include<iostream>
#include<queue>
#include<vector>
#include <limits>


using namespace std;

const int INF = numeric_limits<int>::max();

int n; // ���� ����
int m; // ���� ����

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> m; // ������ ����

	vector<vector<pair<int, int>>> graph(n + 1); // 1-indexed

	for (int i = 0; i < m; i++) 
	{
		int u, v, cost; // u: ���� ���, v: ���� ���, cost: ������ ���
		cin >> u >> v >> cost;
		graph[u].push_back({ v, cost });
	}

	int start, end;
	cin >> start >> end; // ���� ���� -> ���� ����

	// ���ͽ�Ʈ�� �˰���
	vector<int> dist(n + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	dist[start] = 0;
	pq.push({ 0, start }); // cost, ��������

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