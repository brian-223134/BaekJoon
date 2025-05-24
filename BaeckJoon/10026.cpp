#include <iostream>
#include <cstring>

using namespace std;

char map[101][101];
bool visited[101][101];

int dy[4] = { -1, 0, 1, 0 }; // 시계방향
int dx[4] = { 0, 1, 0, -1 };

void dfs(int y, int x)
{
	if (visited[y][x]) return;
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int new_y = y + dy[i];
		int new_x = x + dx[i];
		if (map[new_y][new_x] == map[y][x] && !visited[new_y][new_x])
		{
			dfs(new_y, new_x);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < n; j++)
		{
			map[i][j] = input[j];
		}
	}
	
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j])
			{
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << " ";
	cnt = 0;
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 'G') map[i][j] = 'R';
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j])
			{
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}