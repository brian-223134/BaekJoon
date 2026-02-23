#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; // 거울 개수
    cin >> n;

    int tmp;
    int sub_total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        sub_total += (tmp * 2);
    }

    int _total = 180 * (n - 1);

    cout << _total - sub_total;

    return 0;
}