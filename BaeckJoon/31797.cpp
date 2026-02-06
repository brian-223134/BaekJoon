#include <iostream>
#define MAX 10001

using namespace std;
int arrApartment[10001] = {};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        int hand1, hand2;
        cin >> hand1 >> hand2;
        arrApartment[hand1] = i;
        arrApartment[hand2] = i;
    }

    N %= (2 * M);
    if (N == 0) N = 2 * M;

    int floor = 1;
    for (int i = 1; i < MAX; i++) {
        if (arrApartment[i] != 0) {
            if (floor == N) {
                cout << arrApartment[i];
                break;
            }
            else {
                floor += 1;
            }
        }
    }

    return 0;
}