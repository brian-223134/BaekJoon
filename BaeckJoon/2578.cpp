#include <iostream>
#include <map>

using namespace std;

int board[5][5];
int row[5] = { 0 };
int col[5] = { 0 };
int diag[2] = { 0 }; // diag[0]: �»�-����, diag[1]: ���-����

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<int, pair<int, int> > position; // ���� -> ��ġ ����

    // ����� ������ �Է�
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

    // ��ȸ�ڰ� �θ��� ���� �Է�
    for (int call = 1; call <= 25; ++call) 
    {
        int num;
        cin >> num;

        pair<int, int> pos = position[num];
        int y = pos.first;
        int x = pos.second;

        // �ش� ��ġ�� ��/��/�밢�� ī���� ����
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