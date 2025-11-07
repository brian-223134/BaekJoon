#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_sorted_all(const vector<int>& a)
{
    if (a.size() <= 2) return true;
    for (size_t i = 1; i + 1 < a.size(); ++i) {
        if (a[i] > a[i + 1]) return false;
    }
    return true;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, l, r;
    cin >> n >> l >> r;

    vector<int> num(n + 1);
    for (int i = 1; i <= n; ++i) cin >> num[i];

    sort(num.begin() + l, num.begin() + r + 1);

    cout << (is_sorted_all(num) ? 1 : 0);
    return 0;
}