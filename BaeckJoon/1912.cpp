#include <iostream>
#include <algorithm>
using namespace std;

int num[100000];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    int max_sum = num[0];
    int current_sum = num[0];

    for (int i = 1; i < n; i++)
    {
        current_sum = max(num[i], current_sum + num[i]);
        max_sum = max(max_sum, current_sum);
    }

    cout << max_sum;

    return 0;
}