#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int l, r, c;
char building[30][30][30];
bool visited[30][30][30];
bool trapped;

// ¹æÀ§
int dz[6] = { 0,0,0,0,-1,+1 };
int dy[6] = { -1,+1,0,0,0,0 };
int dx[6] = { 0,0,-1,+1,0,0 };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (1)
	{
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0)
		{
			return 0;
		}

		memset(visited, false, sizeof(visited));
		queue<tuple<int, int, int, int>> q;

		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < r; j++)
			{
				for (int k = 0; k < c; k++)
				{
					cin >> building[i][j][k];

					if (building[i][j][k] == 'S')
					{
						q.push({ i,j,k,0 }); // z, y, x, depth
						visited[i][j][k] = true;
					}
				}
			}
		}

		while (!q.empty())
		{
			trapped = true;
			tuple<int, int, int, int> cur = q.front(); q.pop();
			int z = get<0>(cur);
			int y = get<1>(cur);
			int x = get<2>(cur);
			int depth = get<3>(cur);

			if (building[z][y][x] == 'E')
			{
				cout << "Escaped in " << depth << " minute(s).\n";
				trapped = false;
				break;
			}

			for (int i = 0; i < 6; i++)
			{
				int nz = z + dz[i];
				int ny = y + dy[i];
				int nx = x + dx[i];
				
				if (nz < 0 || ny < 0 || nx < 0 || nz >= l || ny >= r || nx >= c)
				{
					continue;
				}

				if (!visited[nz][ny][nx] && building[nz][ny][nx] == '.' || building[nz][ny][nx] == 'E')
				{
					visited[nz][ny][nx] = true;
					q.push({ nz,ny,nx,depth + 1 });
				}
			}
		}
		if (trapped)
		{
			cout << "Trapped!\n";
		}
	}

	return 0;
}