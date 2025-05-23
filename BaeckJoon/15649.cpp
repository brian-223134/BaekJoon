#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[10];
bool isused[10];

void print_arr(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!isused[i])
		{
			arr[k] = i;
			isused[i] = true;
			print_arr(k + 1);
			isused[i] = 0;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	print_arr(0);
	return 0;
}