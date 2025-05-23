#include <iostream>
#include <vector>

using namespace std;
int n, cnt = 0;

bool isused1[40]; // ���� �࿡ �ִ°�?
bool isused2[40]; // �� ���� �밢�� �� �ִ°�?
bool isused3[40]; // �� ���� �밢�� �� �ִ°�?

void place(int cur)
{
	if (cur == n) { cnt++; return; }

	for (int i = 0; i < n; i++)
	{
		if (isused1[i] || isused2[i + cur] || isused3[cur - i + n - 1]) continue;

		isused1[i] = true;
		isused2[i + cur] = true;
		isused3[cur - i + n - 1] = true;
		place(cur + 1);
		isused1[i] = false;
		isused2[i + cur] = false;
		isused3[cur - i + n - 1] = false;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	place(0);
	cout << cnt;
}