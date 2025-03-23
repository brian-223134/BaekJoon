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
	//자리값이 다를때는 min은 0이 된다. 각 자리수에서 8을 모두 제외한 나머지 정수 조합으로 이룰 수 있기 때문
	if (l.size() != r.size())
	{
		cout << 0;
	}
	else
	{
		for (int i = 0; i < l.size(); i++)
		{
			if (l[i] != r[i]) //앞의 자리수가 같은 것이 중요! (다를 경우 작은 부분의 값을 이용해 8을 회피가능)
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