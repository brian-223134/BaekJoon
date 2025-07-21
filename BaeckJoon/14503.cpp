#include<iostream>
#include<vector>

using namespace std;

// 0: 북쪽, 1: 동쪽, 2: 남쪽, 3: 서쪽
int dy[4] = { -1, 0, +1, 0 };
int dx[4] = { 0,+1,0,-1 };

// 1. 현재 칸이 청소가 안 되었을 때 -> 청소
// 2. 현재 칸 주변 4칸이 모두 청소된 빈칸인 경우
// 2-1. 후진 후 1번으로 다시 진행
// 2-2. 후진 불가 시 작동을 멈춤
// 3. 현재 칸 주변 4칸 중 청소되지 않은 빈칸이 있는 경우
// 3-1. 반시계 방향으로 90도 회전 -> index = (index + 3) mod 4를 이용
// 3-2. 보고 있는 방향이 청소되지 않은 경우 1칸 전진 후 1번으로 돌아감

int n, m; // n by m matrix
int r, c, d; // 로봇의 초기 좌표 및 방향

int result;

int map[51][51]; // 1: 벽, 0: 청소안된 빈칸, 2: 청소된 빈칸

void dfs(int y, int x, int direction)
{
	
	int new_y, new_x;
	bool cleaned = true; // 주변 4칸이 깨끗한지 확인하기
	if (map[y][x] == 0)
	{
		map[y][x] = 2; // 청소가 안된 경우 청소
		result++;
	}

	for (int i = 0; i < 4; i++)
	{
		new_y = y + dy[i];
		new_x = x + dx[i];
		if (map[new_y][new_x] == 0)
		{
			cleaned = false;
		}
	}

	if (cleaned == true)
	{
		// 후진 방향 설정
		new_y = y + dy[(direction + 2) % 4];
		new_x = x + dx[(direction + 2) % 4];
		if (map[new_y][new_x] == 1)
		{
			return;
		}
		else
		{
			dfs(new_y, new_x, direction);
		}
	}
	else
	{
		int cnt = 4;
		do
		{
			cnt--;
			direction = (direction + 3) % 4; // 왼쪽으로 회전
			new_y = y + dy[direction];
			new_x = x + dx[direction];
			if (map[new_y][new_x] == 0)
			{
				dfs(new_y, new_x, direction);
				return;
			}
		} while (cnt > 0);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	cin >> r >> c >> d;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	result = 0;

	dfs(r, c, d);
	cout << result;
	return 0;
}