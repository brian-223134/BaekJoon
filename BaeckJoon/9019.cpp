#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int A, B;
        cin >> A >> B;

        // 방문 / 부모 / 도달연산 기록
        bool visited[10000];
        int parent[10000];
        char viaOp[10000];
        memset(visited, 0, sizeof(visited));

        queue<int> q;
        visited[A] = true;
        parent[A] = -1;      // 시작점 표시
        q.push(A);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (cur == B) break;

            // D
            int nxt = (cur * 2) % 10000;
            if (!visited[nxt]) {
                visited[nxt] = true;
                parent[nxt] = cur;
                viaOp[nxt] = 'D';
                q.push(nxt);
            }
            // S
            nxt = (cur == 0) ? 9999 : cur - 1;
            if (!visited[nxt]) {
                visited[nxt] = true;
                parent[nxt] = cur;
                viaOp[nxt] = 'S';
                q.push(nxt);
            }
            // L
            nxt = (cur % 1000) * 10 + cur / 1000;
            if (!visited[nxt]) {
                visited[nxt] = true;
                parent[nxt] = cur;
                viaOp[nxt] = 'L';
                q.push(nxt);
            }
            // R
            nxt = (cur / 10) + (cur % 10) * 1000;
            if (!visited[nxt]) {
                visited[nxt] = true;
                parent[nxt] = cur;
                viaOp[nxt] = 'R';
                q.push(nxt);
            }
        }

        // 역추적
        string answer;
        for (int v = B; parent[v] != -1; v = parent[v]) {
            answer.push_back(viaOp[v]);
        }
        reverse(answer.begin(), answer.end());
        cout << answer << '\n';
    }

    return 0;
}