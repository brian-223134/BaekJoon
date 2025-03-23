#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string l, r;
	cin >> l >> r;
	int min = 0;
	//�ڸ����� �ٸ����� min�� 0�� �ȴ�. �� �ڸ������� 8�� ��� ������ ������ ���� �������� �̷� �� �ֱ� ����
	if (l.size() != r.size())
	{
		cout << 0;
	}
	else
	{
		for (int i = 0; i < l.size(); i++)
		{
			if (l[i] != r[i]) //���� �ڸ����� ���� ���� �߿�! (�ٸ� ��� ���� �κ��� ���� �̿��� 8�� ȸ�ǰ���)
				break;

			if (l[i] == r[i] && l[i] == '8')
			{
				min++;
			}
		}

		cout << min;
	}
	return 0;
}