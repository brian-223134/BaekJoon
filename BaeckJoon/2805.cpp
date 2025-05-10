#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// n: 나무 개수, m: 상근이가 필요한 목재 길이

	int n, m, temp, max = 0;
	cin >> n >> m;
	vector<int> tree;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		tree.push_back(temp);
		if (max < temp)
			max = temp;
	}

	int left = 0, right = max, ans = 0;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		long long wood = 0;
		for (int i = 0; i < n; i++)
		{
			if (tree[i] - mid < 0)
				continue;
			wood += (tree[i] - mid);
		}

		if (wood >= m)
		{
			ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << ans;
	return 0;
}