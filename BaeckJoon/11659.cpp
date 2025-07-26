#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int n, m; // n: 수 개수, m: 테스트 횟수

int num[100001];
int sum[100001] = { 0, };

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
    }

    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + num[i];
    }

    for (int i = 0; i < m; i++)
    {
        int start, end;
        cin >> start >> end;
        cout << sum[end] - sum[start - 1] << '\n';
    }

    return 0;
}