#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
#include <set>
#include <unordered_map>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<int, int> point;

    vector<int> arr(n);
    set<int> unique_num;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        unique_num.insert(arr[i]);
    }

    int idx = 0;
    for (int num : unique_num)
    {
        point[num] = idx++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << point[arr[i]] << ' ';
    }

    return 0;
}
