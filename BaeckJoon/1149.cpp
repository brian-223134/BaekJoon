#include <iostream>
#include <algorithm>

using namespace std;

int color_house[1001][3] = {0};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; int cost[3];
	color_house[0][0] = 0; color_house[0][1] = 0; color_house[0][2] = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> cost[0] >> cost[1] >> cost[2];
		color_house[i][0] = min(color_house[i - 1][1], color_house[i - 1][2]) + cost[0];
		color_house[i][1] = min(color_house[i - 1][0], color_house[i - 1][2]) + cost[1];
		color_house[i][2] = min(color_house[i - 1][0], color_house[i - 1][1]) + cost[2];
	}

	cout << min(color_house[n][0], min(color_house[n][1], color_house[n][2]));
	return 0;
}