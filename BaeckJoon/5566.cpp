#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; // n: 도착 칸(보드 크기), m: 주사위 던진 횟수
    if (!(cin >> n >> m)) return 0;

    vector<int> block(n + 1, 0); // 1 ~ n번 칸의 지시 사항
    vector<int> seq(m, 0);       // 주사위 던진 결과 리스트

    for (int i = 1; i <= n; i++) {
        cin >> block[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> seq[i];
    }

    int pos = 1; // 현재 위치 (1번 칸에서 시작)
    int count = 0; // 주사위를 던진 횟수 카운트

    for (int i = 0; i < m; i++) {
        count++;

        pos += seq[i];

        if (pos >= n) {
            break;
        }

        pos += block[pos];

        if (pos >= n) {
            break;
        }
    }

    cout << count << "\n";

    return 0;
}