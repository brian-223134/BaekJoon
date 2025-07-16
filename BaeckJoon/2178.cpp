#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n, m;
char map[101][101];
int dis[101][101] = { 0, };
// �����¿�
int dx[4] = { 0, 0, -1, +1 };
int dy[4] = { -1, 1, 0, 0 };

int bfs(int end_y, int end_x)
{
	queue<pair<int, int>> q;
	q.push({ 1,1 }); //���� ��ǥ
	dis[1][1] = 1; //�Ÿ� �ʱ�ȭ, ���� ��ġ���� 1�� �ʱ�ȭ

	while (!q.empty())
	{
		pair<int, int> cur = q.front(); q.pop();
		int cur_y = cur.first;
		int cur_x = cur.second;

		// �����¿� ������� Ž���� ����
		for (int i = 0; i < 4; i++)
		{
			int new_y = cur_y + dy[i];
			int new_x = cur_x + dx[i];
			if (dis[new_y][new_x] == 0 && map[new_y][new_x] == '1')
			{
				dis[new_y][new_x] = dis[cur_y][cur_x] + 1;
				q.push({ new_y,new_x });
			}
		}
	}

	return dis[end_y][end_x];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	string map_line;
	for (int i = 1; i <= n; i++)
	{
		cin >> map_line;
		for (int j = 1; j <= m; j++)
		{
			map[i][j] = map_line[j-1]; // ������ (1,1)����, string index�� 0����
		}
	}
	cout << bfs(n, m);
	return 0;
}