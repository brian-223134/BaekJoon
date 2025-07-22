#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int m, n, k;
int map[101][101];
bool visited[101][101];
int area;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void dfs(int y, int x)
{
	visited[y][x] = true;
	area++;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= m || nx < 0 || nx >= n)
			continue;

		if (map[ny][nx] == 0 && !visited[ny][nx])
			dfs(ny, nx);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> m >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int y = y1; y < y2; y++) 
		{
			for (int x = x1; x < x2; x++) 
			{
				map[y][x] = 1;
			}
		}
	}

	vector<int> result;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 0 && !visited[i][j])
			{
				area = 0;
				dfs(i, j);
				result.push_back(area);
			}
		}
	}

	sort(result.begin(), result.end());

	cout << result.size() << '\n';
	for (int i : result)
		cout << i << " ";
	cout << '\n';
}
