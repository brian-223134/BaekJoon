#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<long long> nums;

void dfs(long long num, int last_digit)
{
    nums.push_back(num);
    for (int i = 0; i < last_digit; i++) 
    {
        dfs(num * 10 + i, i);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    // 1자리~10자리 줄어드는 수 생성
    for (int i = 0; i <= 9; i++) 
    {
        dfs(i, i);
    }

    sort(nums.begin(), nums.end());

    if (n > nums.size()) cout << -1;
    else cout << nums[n-1];

    return 0;
}