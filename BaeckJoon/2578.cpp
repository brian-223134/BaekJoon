#include <iostream>
#include <map>

using namespace std;

int board[5][5];
int row[5] = { 0 };
int col[5] = { 0 };
int diag[2] = { 0 }; // diag[0]: 좌상-우하, diag[1]: 우상-좌하

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<int, pair<int, int> > position; // 숫자 -> 위치 매핑

    // 사용자 빙고판 입력
    for (int i = 0; i < 5; ++i) 
    {
        for (int j = 0; j < 5; ++j) 
        {
            int num;
            cin >> num;
            board[i][j] = num;
            position[num] = make_pair(i, j);
        }
    }

    int bingo = 0;

    // 사회자가 부르는 숫자 입력
    for (int call = 1; call <= 25; ++call) 
    {
        int num;
        cin >> num;

        pair<int, int> pos = position[num];
        int y = pos.first;
        int x = pos.second;

        // 해당 위치의 줄/열/대각선 카운터 증가
        if (++row[y] == 5) ++bingo;
        if (++col[x] == 5) ++bingo;
        if (y == x && ++diag[0] == 5) ++bingo;
        if (y + x == 4 && ++diag[1] == 5) ++bingo;

        if (bingo >= 3) 
        {
            cout << call << '\n';
            break;
        }
    }

    return 0;
}