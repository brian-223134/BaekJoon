#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// CCTV ������ ������ ����ü
typedef struct CCTV 
{
    int r, c, type;
} CCTV;

int N, M;
int min_blind_spot = 100; // �簢���� �ּڰ� (N, M <= 8 �̹Ƿ� 64���� ū ������ �ʱ�ȭ)
vector<CCTV> cctv_list; // 1~4�� CCTV ���, 5 �� CCTV�� ������ �̸� ó�� ���� (�׻� 4���� �����̱� ����)

// �����¿� ���� ����
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

// Ư�� �������� ���� ������ ǥ���ϴ� �Լ�
void watch(vector<vector<int>>& board, int r, int c, int dir) 
{
    dir %= 4; // 0~3 ���� ������ ����
    while (true)
    {
        r += dr[dir];
        c += dc[dir];

        // ���� ������ ����ų� ��(6)�� ������ ����
        if (r < 0 || r >= N || c < 0 || c >= M || board[r][c] == 6) 
        {
            break;
        }

        // ���� ������ �� ����(0)�� ���� ��(#)���� ǥ��
        if (board[r][c] == 0) 
        {
            board[r][c] = 7; // '#' ��� 7�� ǥ��
        }
    }
}

// ��Ʈ��ŷ�� ������ ��� �Լ�
// cctv_idx: ���� Ž���� cctv�� �ε���, board: ���� ������ �繫�� ��
void solve(int cctv_idx, vector<vector<int>> board) 
{
    // ��� CCTV�� ������ �����ߴٸ�
    if (cctv_idx == cctv_list.size()) 
    {
        int current_blind_spot = 0;
        // ���� ���� �簢����(0) ���� ���
        for (int i = 0; i < N; ++i) 
        {
            for (int j = 0; j < M; ++j) 
            {
                if (board[i][j] == 0) 
                {
                    current_blind_spot++;
                }
            }
        }
        // �ּڰ� ����
        min_blind_spot = min(min_blind_spot, current_blind_spot);
        return;
    }

    // ���; ���� CCTV�� ������ �����ͼ� ��� ���� ���� Ž��
    CCTV current_cctv = cctv_list[cctv_idx];
    int r = current_cctv.r;
    int c = current_cctv.c;
    int type = current_cctv.type;

    vector<vector<int>> temp_board; // ���� ��ͷ� �Ѱ��� �� ���纻

    switch (type) 
    {
    case 1: // 1�� CCTV: 4���� ����
        for (int i = 0; i < 4; ++i)
        {
            temp_board = board;
            watch(temp_board, r, c, i);
            solve(cctv_idx + 1, temp_board);
        }
        break;

    case 2: // 2�� CCTV: 2���� ���� (����, �¿�)
        // ����
        temp_board = board;
        watch(temp_board, r, c, 0);
        watch(temp_board, r, c, 2);
        solve(cctv_idx + 1, temp_board);
        // �¿�
        temp_board = board;
        watch(temp_board, r, c, 1);
        watch(temp_board, r, c, 3);
        solve(cctv_idx + 1, temp_board);
        break;

    case 3: // 3�� CCTV: 4���� ���� (90��)
        for (int i = 0; i < 4; ++i)
        {
            temp_board = board;
            watch(temp_board, r, c, i);
            watch(temp_board, r, c, i + 1);
            solve(cctv_idx + 1, temp_board);
        }
        break;

    case 4: // 4�� CCTV: 4���� ���� (�� ����)
        for (int i = 0; i < 4; ++i)
        {
            temp_board = board;
            watch(temp_board, r, c, i);
            watch(temp_board, r, c, i + 1);
            watch(temp_board, r, c, i + 2);
            solve(cctv_idx + 1, temp_board);
        }
        break;
    }
}

int main(void) 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    vector<vector<int>> office_map(N, vector<int>(M));
    vector<pair<int, int>> cctv5_pos; // 5�� CCTV ��ġ ����

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j)
        {
            cin >> office_map[i][j];
            if (office_map[i][j] >= 1 && office_map[i][j] <= 4) 
            {
                cctv_list.push_back({ i, j, office_map[i][j] });
            }
            else if (office_map[i][j] == 5)
            {
                cctv5_pos.push_back({ i, j });
            }
        }
    }

    // 5�� CCTV�� �̸� ó��
    for (auto pos : cctv5_pos) 
    {
        watch(office_map, pos.first, pos.second, 0); // ��
        watch(office_map, pos.first, pos.second, 1); // ��
        watch(office_map, pos.first, pos.second, 2); // ��
        watch(office_map, pos.first, pos.second, 3); // ��
    }

    // ��Ʈ��ŷ ����
    solve(0, office_map);

    cout << min_blind_spot << "\n";

    return 0;
}