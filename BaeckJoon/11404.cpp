#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int INF = 1e9;

int n, m; // n: 도시 개수, m: 버스 개수 (노드개수 = n, 간선개수 = m)

int city[101][101];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) city[i][j] = 0;
			else city[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		city[start][end] = min(city[start][end], cost);
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (city[i][j] > city[i][k] + city[k][j])
				{
					city[i][j] = city[i][k] + city[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (city[i][j] == INF) cout << 0 << ' ';
			else cout << city[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}