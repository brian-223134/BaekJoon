#include <iostream>
#include <vector>
#include <cmath> // abs() 함수를 위해 추가

using namespace std;

int n, l;
int arr[100][100];

// type 0: 가로, type 1: 세로
bool is_road(int idx, int type) 
{
    // 각 줄을 검사하기 편하도록 1차원 배열로 복사
    vector<int> line(n);
    for (int i = 0; i < n; i++) 
    {
        if (type == 0) { // 가로 길
            line[i] = arr[idx][i];
        }
        else { // 세로 길
            line[i] = arr[i][idx];
        }
    }

    // 경사로 설치 여부를 기록할 배열
    bool visited[100] = { false };

    for (int i = 0; i < n - 1; i++) 
    {
        int diff = line[i] - line[i + 1];

        // 높이 차이가 1보다 크면 길을 만들 수 없음
        if (abs(diff) > 1)
        {
            return false;
        }

        // 높이가 같으면 통과
        if (diff == 0) 
        {
            continue;
        }

        // 내리막 경사로 (현재 > 다음)
        if (diff == 1) 
        {
            // 앞으로 L개의 칸을 확인해야 함
            for (int j = 1; j <= l; j++) 
            {
                // 1. 범위를 벗어나거나
                // 2. 경사로를 놓을 곳의 높이가 다르거나
                // 3. 이미 다른 경사로가 설치되어 있다면 불가능
                if (i + j >= n || line[i + 1] != line[i + j] || visited[i + j]) 
                {
                    return false;
                }
            }
            // 경사로 설치
            for (int j = 1; j <= l; j++) 
            {
                visited[i + j] = true;
            }
        }
        // 오르막 경사로 (현재 < 다음)
        else if (diff == -1)
        {
            // 뒤로 L개의 칸을 확인해야 함
            for (int j = 0; j < l; j++)
            {
                // 1. 범위를 벗어나거나
                // 2. 경사로를 놓을 곳의 높이가 다르거나
                // 3. 이미 다른 경사로가 설치되어 있다면 불가능
                if (i - j < 0 || line[i] != line[i - j] || visited[i - j]) 
                {
                    return false;
                }
            }
            // 경사로 설치
            for (int j = 0; j < l; j++) 
            {
                visited[i - j] = true;
            }
        }
    }

    return true; // 모든 검사를 통과하면 길 완성
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int result = 0;

    // 가로 방향으로 길 찾기
    for (int i = 0; i < n; i++) 
    {
        if (is_road(i, 0)) 
        {
            result++;
        }
    }

    // 세로 방향으로 길 찾기
    for (int i = 0; i < n; i++) 
    {
        if (is_road(i, 1)) 
        {
            result++;
        }
    }

    cout << result;

    return 0;
}