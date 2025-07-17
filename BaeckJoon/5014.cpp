#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int f, s, g, u, d;
// s: ���� ��ġ, g: �繫�� ��ġ, f: �ְ���
// u: u��ŭ + ��ġ �̵�, d: d��ŭ - ��ġ �̵�

bool visited[1000001] = { false, };
int dis[1000001];


int bfs()
{
	queue<int> q;
	q.push(s); // ������ġ �Է�
	visited[s] = true;
	dis[s] = 0;

	while (!q.empty())
	{
		int cur = q.front(); q.pop();

		if (cur == g) return dis[cur];

		for (int next : {cur + u, cur - d})
		{
			if (next <= 0 || next > f) continue; // ���� ������ ��� ���
			if (!visited[next])
			{
				visited[next] = true;
				dis[next] = dis[cur] + 1;
				q.push(next);
			}
		}
	}
	return -1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> f >> s >> g >> u >> d;
	int result = bfs();
	if (result == -1)
	{
		cout << "use the stairs";
	}
	else
	{
		cout << result;
	}
	return 0;
}