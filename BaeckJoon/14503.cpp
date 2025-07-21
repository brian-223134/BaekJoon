#include<iostream>
#include<vector>

using namespace std;

// 0: ����, 1: ����, 2: ����, 3: ����
int dy[4] = { -1, 0, +1, 0 };
int dx[4] = { 0,+1,0,-1 };

// 1. ���� ĭ�� û�Ұ� �� �Ǿ��� �� -> û��
// 2. ���� ĭ �ֺ� 4ĭ�� ��� û�ҵ� ��ĭ�� ���
// 2-1. ���� �� 1������ �ٽ� ����
// 2-2. ���� �Ұ� �� �۵��� ����
// 3. ���� ĭ �ֺ� 4ĭ �� û�ҵ��� ���� ��ĭ�� �ִ� ���
// 3-1. �ݽð� �������� 90�� ȸ�� -> index = (index + 3) mod 4�� �̿�
// 3-2. ���� �ִ� ������ û�ҵ��� ���� ��� 1ĭ ���� �� 1������ ���ư�

int n, m; // n by m matrix
int r, c, d; // �κ��� �ʱ� ��ǥ �� ����

int result;

int map[51][51]; // 1: ��, 0: û�Ҿȵ� ��ĭ, 2: û�ҵ� ��ĭ

void dfs(int y, int x, int direction)
{
	
	int new_y, new_x;
	bool cleaned = true; // �ֺ� 4ĭ�� �������� Ȯ���ϱ�
	if (map[y][x] == 0)
	{
		map[y][x] = 2; // û�Ұ� �ȵ� ��� û��
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
		// ���� ���� ����
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
			direction = (direction + 3) % 4; // �������� ȸ��
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