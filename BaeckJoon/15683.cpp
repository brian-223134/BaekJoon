#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// CCTV 정보를 저장할 구조체
typedef struct CCTV 
{
    int r, c, type;
} CCTV;

int N, M;
int min_blind_spot = 100; // 사각지대 최솟값 (N, M <= 8 이므로 64보다 큰 값으로 초기화)
vector<CCTV> cctv_list; // 1~4번 CCTV 목록, 5 번 CCTV는 사전에 미리 처리 가능 (항상 4방향 감시이기 때문)

// 상하좌우 감시 벡터
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

// 특정 방향으로 감시 영역을 표시하는 함수
void watch(vector<vector<int>>& board, int r, int c, int dir) 
{
    dir %= 4; // 0~3 사이 값으로 고정
    while (true)
    {
        r += dr[dir];
        c += dc[dir];

        // 맵의 범위를 벗어나거나 벽(6)을 만나면 종료
        if (r < 0 || r >= N || c < 0 || c >= M || board[r][c] == 6) 
        {
            break;
        }

        // 감시 가능한 빈 공간(0)을 감시 중(#)으로 표시
        if (board[r][c] == 0) 
        {
            board[r][c] = 7; // '#' 대신 7로 표시
        }
    }
}

// 백트래킹을 수행할 재귀 함수
// cctv_idx: 현재 탐색할 cctv의 인덱스, board: 현재 상태의 사무실 맵
void solve(int cctv_idx, vector<vector<int>> board) 
{
    // 모든 CCTV의 방향을 결정했다면
    if (cctv_idx == cctv_list.size()) 
    {
        int current_blind_spot = 0;
        // 현재 맵의 사각지대(0) 개수 계산
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
        // 최솟값 갱신
        min_blind_spot = min(min_blind_spot, current_blind_spot);
        return;
    }

    // 재귀; 현재 CCTV의 정보를 가져와서 모든 방향 조합 탐색
    CCTV current_cctv = cctv_list[cctv_idx];
    int r = current_cctv.r;
    int c = current_cctv.c;
    int type = current_cctv.type;

    vector<vector<int>> temp_board; // 다음 재귀로 넘겨줄 맵 복사본

    switch (type) 
    {
    case 1: // 1번 CCTV: 4가지 방향
        for (int i = 0; i < 4; ++i)
        {
            temp_board = board;
            watch(temp_board, r, c, i);
            solve(cctv_idx + 1, temp_board);
        }
        break;

    case 2: // 2번 CCTV: 2가지 방향 (상하, 좌우)
        // 상하
        temp_board = board;
        watch(temp_board, r, c, 0);
        watch(temp_board, r, c, 2);
        solve(cctv_idx + 1, temp_board);
        // 좌우
        temp_board = board;
        watch(temp_board, r, c, 1);
        watch(temp_board, r, c, 3);
        solve(cctv_idx + 1, temp_board);
        break;

    case 3: // 3번 CCTV: 4가지 방향 (90도)
        for (int i = 0; i < 4; ++i)
        {
            temp_board = board;
            watch(temp_board, r, c, i);
            watch(temp_board, r, c, i + 1);
            solve(cctv_idx + 1, temp_board);
        }
        break;

    case 4: // 4번 CCTV: 4가지 방향 (세 방향)
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
    vector<pair<int, int>> cctv5_pos; // 5번 CCTV 위치 저장

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

    // 5번 CCTV는 미리 처리
    for (auto pos : cctv5_pos) 
    {
        watch(office_map, pos.first, pos.second, 0); // 상
        watch(office_map, pos.first, pos.second, 1); // 우
        watch(office_map, pos.first, pos.second, 2); // 하
        watch(office_map, pos.first, pos.second, 3); // 좌
    }

    // 백트래킹 시작
    solve(0, office_map);

    cout << min_blind_spot << "\n";

    return 0;
}