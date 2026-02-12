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

    int e, s, m;
    cin >> e >> s >> m; // 1 ¡Â E ¡Â 15, 1 ¡Â S ¡Â 28, 1 ¡Â M ¡Â 19

    if (e >= 15) e = e % 15;
    if (m >= 19) m = m % 19;

    int num, q = 0;

    while (1) {

        num = 28 * q + s;
        if (num % 15 != e || num % 19 != m) {
            q++;
        }
        else {
            break;
        }
    }

    cout << num << "\n";

    return 0;
}