#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
#include <cmath>

using namespace std;

int n;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    vector<int> num(n);
    long long _sum = 0;
    vector<int> cnt(8001, 0); // -4000 ~ 4000 범위

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        _sum += num[i];
        cnt[num[i] + 4000]++;
    }

    sort(num.begin(), num.end());

    // 산술평균 (반올림)
    int mean = (int)llround((long double)_sum / n);
    cout << mean << '\n';

    // 중앙값
    cout << num[n / 2] << '\n';

    // 최빈값 (여러 개면 두 번째로 작은 값)
    int maxFreq = 0;
    for (int c : cnt) maxFreq = max(maxFreq, c);

    int mode = 0;
    bool firstFound = false;
    for (int i = 0; i <= 8000; ++i)
    {
        if (cnt[i] == maxFreq)
        {
            if (!firstFound)
            {
                mode = i - 4000;
                firstFound = true;
            }
            else
            {
                mode = i - 4000; // 두 번째로 작은 값
                break;
            }
        }
    }
    cout << mode << '\n';

    // 범위
    cout << (num.back() - num.front()) << '\n';

    return 0;
}