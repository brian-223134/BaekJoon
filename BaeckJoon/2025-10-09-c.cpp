#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int snow[2001][2001];
long long rowSum[2001], colSum[2001];
bool rowRemoved[2001], colRemoved[2001];

struct Node {
    long long sum;
    int type; // 0 = row, 1 = col
    int idx;
    bool operator>(const Node& other) const {
        if (sum != other.sum) return sum > other.sum;
        return type > other.type;
    }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) 
    {
        long long rs = 0;
        for (int j = 0; j < M; j++) 
        {
            cin >> snow[i][j];
            rs += snow[i][j];
        }
        rowSum[i] = rs;
    }
    for (int j = 0; j < M; j++)
    {
        long long cs = 0;
        for (int i = 0; i < N; i++) cs += snow[i][j];
        colSum[j] = cs;
    }

    // 최소 P는 "현재 남아있는 행/열 중 가장 합이 작은 것을 계속 제거" 했을 때
    // 등장하는 합의 최대값과 동일할 듯?

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    for (int i = 0; i < N; ++i) pq.push({ rowSum[i], 0, i });
    for (int j = 0; j < M; ++j) pq.push({ colSum[j], 1, j });

    int rowsLeft = N, colsLeft = M;
    long long answer = 0;

    while (rowsLeft > 0 && colsLeft > 0 && !pq.empty()) 
    {
        Node cur = pq.top(); pq.pop();

        if (cur.type == 0) 
        {
            int r = cur.idx;
            if (rowRemoved[r] || cur.sum != rowSum[r]) continue;
            answer = max(answer, rowSum[r]);
            rowRemoved[r] = true;
            --rowsLeft;
            // 이 행 제거 -> 남아있는 열들의 합 갱신
            for (int c = 0; c < M; ++c) 
            {
                if (colRemoved[c]) continue;
                colSum[c] -= snow[r][c];
                pq.push({ colSum[c], 1, c });
            }
        } 
        else 
        {
            int c = cur.idx;
            if (colRemoved[c] || cur.sum != colSum[c]) continue;
            answer = max(answer, colSum[c]);
            colRemoved[c] = true;
            --colsLeft;
            // 이 열 제거 -> 남아있는 행들의 합 갱신
            for (int r = 0; r < N; ++r) 
            {
                if (rowRemoved[r]) continue;
                rowSum[r] -= snow[r][c];
                pq.push({ rowSum[r], 0, r });
            }
        }
    }

    // 모든 행 또는 모든 열이 제거되면 모든 칸 제거 완료
    cout << answer << '\n';
    return 0;
}
