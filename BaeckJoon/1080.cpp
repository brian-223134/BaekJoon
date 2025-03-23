#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

char arr1[50][50];
char arr2[50][50];

void mapping(int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char num;
			cin >> num;
			arr1[i][j] = num;

		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char num;
			cin >> num;
			arr2[i][j] = num;
		}
	}
}

void flip(char arr[][50], int y, int x)
{
	for (int i = y; i < y + 3; i++)
	{
		for (int j = x; j < x + 3; j++)
		{
			if (arr[i][j] == '1')
				arr[i][j] = '0';
			else if (arr[i][j] == '0')
				arr[i][j] = '1';
		}
	}
}

int sol(int n, int m)
{
	int ans = 0;
	//n-2,m-2까지 돌아야 3*3 sub-matrix 탐색에서 메모리 영역을 올바르게 사용 가능함.
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 0; j < m - 2; j++)
		{
			if (arr1[i][j] != arr2[i][j])
			{
				flip(arr1, i, j);
				ans++; //flip 한번당 ans 값을 올려야함
			}
		}
	}
	//다 돌리고 값이 다른 부분이 있다면 -1로 ans를 출력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr1[i][j] != arr2[i][j])
				return -1;
		}
	}

	return ans;
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	mapping(n, m);
	int solution = sol(n, m);
	cout << solution << endl;

	return 0;
}