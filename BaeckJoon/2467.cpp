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

    int N;
    if (!(cin >> N)) return 0;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int l = 0, r = N - 1;
    long long bestAbs = (1LL << 62);
    int bestL = l, bestR = r;

    while (l < r) {
        long long sum = A[l] + A[r];
        long long absSum = sum >= 0 ? sum : -sum;

        if (absSum < bestAbs) {
            bestAbs = absSum;
            bestL = l; bestR = r;
            if (bestAbs == 0) break;
        }

        if (sum < 0) l++;
        else r--;
    }

    cout << A[bestL] << ' ' << A[bestR] << '\n';
    return 0;
}