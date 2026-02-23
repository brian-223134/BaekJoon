#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    // 상태를 저장할 배열 (-1: 알 수 없음, 0: 없음, 1: 있음)
    vector<int> P(n + 1, -1);
    vector<int> M(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int a, c;
        char b;
        cin >> a >> b >> c;

        // 입력받은 기능(P 또는 M)에 따라 배열 상태 업데이트
        if (b == 'P') {
            P[a] = c;
        }
        else if (b == 'M') {
            M[a] = c;
        }
    }

    int min_plants = 0;
    int max_plants = 0;

    for (int i = 1; i <= n; i++) {
        // 최소 식물의 수: P가 확실히 1이고, M이 확실히 0인 경우
        if (P[i] == 1 && M[i] == 0) {
            min_plants++;
        }

        // 최대 식물의 수: 식물일 가능성이 있는 경우
        // P가 0이 아니고 (1이거나 -1), M이 1이 아닌 (0이거나 -1) 경우
        if (P[i] != 0 && M[i] != 1) {
            max_plants++;
        }
    }

    cout << min_plants << " " << max_plants << "\n";

    return 0;
}