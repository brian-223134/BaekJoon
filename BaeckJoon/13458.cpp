#include <iostream>
#include <vector>

using namespace std;

// n개의 시험장, i번째 시험장에서는 응시자수가 A_i명이다.
// 각 시험장에는 총감독관이 오직 1명, 부감독관은 여러명이 있을 수 있음.
// B: 총감독관이 감독할 수 있는 응시자 수, C: 부감독관이 감독할 수 있는 응시자 수

// 응시생 모두 감독 필요, 최소 감독관 수 찾기

// 1. loop를 돌면서 a_i - b 값을 a_i에 갱신한다. 그리고 각 횟수마다 cnt++를 진행.
// (이 경우 a_i <= 0이 되었을 때, a_i = 0으로 초기화)
// 2. 이후 갱신된 a_i값에 대하여 temp = a_i % c
// temp != 0인 경우 cnt += (int) (a_i / c) + 1
// temp == 0인 경우 cnt += a_i / c

long long n;
long long b, c;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	vector<int> a(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cin >> b >> c;

	long long temp, cnt = 0;
	for (int i = 0; i < n; i++)
	{
		a[i] = a[i] - b;
		cnt++;
		if (a[i] <= 0) continue;
		temp = a[i] % c;
		if (temp == 0) cnt += a[i] / c;
		else cnt += (int)(a[i] / c) + 1;
	}

	cout << cnt;
	
	return 0;
}