#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int m, n; // m: 가로, n: 세로
int box[1001][1001];

// 상하좌우
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

// 토마토 상태; 1: 익음, 2: 안 익음, 3: 비어있음

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	queue<tuple<int, int>> q;
	int unripe = 0; // 안 익은 개수

	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> box[i][j];
			if (box[i][j] == 1)
			{
				q.push({ i,j }); // 익은 사과는 큐에 삽입
			}
			else if (box[i][j] == 0)
			{
				unripe++;
			}
		}
	}

	if (unripe == 0) { // 처음부터 다 익음
		cout << 0;
		return 0;
	}

	int day = -1;
	while (!q.empty())
	{
		int size = q.size();
		day++;
		while (size--)
		{
			tuple<int, int> cur = q.front();
			q.pop();
			int y = get<0>(cur);
			int x = get<1>(cur);

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || ny >= n || nx < 0 || nx >= m)
				{
					continue;
				}
				if (box[ny][nx] == 0)
				{
					box[ny][nx] = 1;
					unripe--;
					q.push({ ny,nx });
				}
			}
		}
	}

	cout << (unripe == 0 ? day : -1);
	return 0;
}