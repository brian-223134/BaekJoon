#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int n, s;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n >> s;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int min_len = n + 1;
    int sum = 0, left = 0;

    for (int right = 0; right < n; right++)
    {
        sum += arr[right];

        while (sum >= s)
        {
            min_len = min(min_len, right - left + 1);
            sum -= arr[left++];
        }
    }

    if (min_len == n + 1)
        cout << 0 << '\n';
    else
        cout << min_len << '\n';

    return 0;
}