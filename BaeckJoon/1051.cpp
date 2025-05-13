#include <iostream>
#include <algorithm>

using namespace std;

char square[50][50];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> square[i][j];
		}
	}

	int max_area = 1; // 정사각형의 최소 넓이는 1 (한 칸)

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int len = 1; i + len < n && j + len < m; len++) // 변의 길이 시도
			{
				if (square[i][j] == square[i][j + len] &&
					square[i][j] == square[i + len][j] &&
					square[i][j] == square[i + len][j + len])
				{
					int area = (len + 1) * (len + 1);
					max_area = max(max_area, area);
				}
			}
		}
	}

	cout << max_area << endl;
	return 0;
}