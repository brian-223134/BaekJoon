#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int a, b, n, k;
    cin >> a >> b >> n >> k; // a 중대, 각 중대 b 소대, 각 소대 n명, k번째 입소

    // 총 수용 가능 인원: a * b * n
    long long idx = k - 1;
    long long platoonIdx = idx / n;
    int company = (int)(platoonIdx / b) + 1;
    int platoon = (int)(platoonIdx % b) + 1;

    cout << company << ' ' << platoon << '\n';
    return 0;
}