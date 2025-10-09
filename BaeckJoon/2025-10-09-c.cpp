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

    // �ּ� P�� "���� �����ִ� ��/�� �� ���� ���� ���� ���� ��� ����" ���� ��
    // �����ϴ� ���� �ִ밪�� ������ ��?

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
            // �� �� ���� -> �����ִ� ������ �� ����
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
            // �� �� ���� -> �����ִ� ����� �� ����
            for (int r = 0; r < N; ++r) 
            {
                if (rowRemoved[r]) continue;
                rowSum[r] -= snow[r][c];
                pq.push({ rowSum[r], 0, r });
            }
        }
    }

    // ��� �� �Ǵ� ��� ���� ���ŵǸ� ��� ĭ ���� �Ϸ�
    cout << answer << '\n';
    return 0;
}
