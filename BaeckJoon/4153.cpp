#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
	vector<int> num;
	int a, b, c;
	int sum;

	do
	{
		sum = 0;
		cin >> a; num.push_back(a);
		cin >> b; num.push_back(b);
		cin >> c; num.push_back(c);
		if (a == 0 && b == 0 && c == 0)
		{
			break;
		}
		if (a == 0 || b == 0 || c == 0)
		{
			cout << "wrong\n";
		}
		int max_index = max_element(num.begin(), num.end()) - num.begin();
		for (int i = 0; i < 3; i++)
		{
			if (i == max_index)
				continue;
			sum += num[i] * num[i];
		}
		if (sum == num[max_index] * num[max_index])
		{
			cout << "right\n";
		}
		else
		{
			cout << "wrong\n";
		}
		num.clear();
	} while (1);

	return 0;
}