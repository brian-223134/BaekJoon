#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1000001;
vector<int> kminsu;
int pre_node[MAX]; // 경로 추적을 위한 이전 노드 저장
int pre_val[MAX];  // 경로 추적을 위한 사용된 금민수 저장
bool visited[MAX];

// 1. 모든 금민수를 생성하여 정렬하는 함수
void generate_kminsu(long long current, int limit) {
    if (current > limit) return;
    if (current > 0) kminsu.push_back((int)current);

    generate_kminsu(current * 10 + 4, limit);
    generate_kminsu(current * 10 + 7, limit);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    // 금민수 생성 및 오름차순 정렬
    generate_kminsu(0, N);
    sort(kminsu.begin(), kminsu.end());

    // 2. BFS 탐색 시작
    queue<int> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == N) break;

        for (int k : kminsu) {
            int next = curr + k;

            if (next <= N && !visited[next]) {
                visited[next] = true;
                pre_node[next] = curr;
                pre_val[next] = k;
                q.push(next);
            }
        }
    }

    // 3. 결과 출력 및 경로 복원
    if (!visited[N]) {
        cout << -1 << "\n";
    }
    else {
        vector<int> path;
        int temp = N;
        while (temp != 0) {
            path.push_back(pre_val[temp]);
            temp = pre_node[temp];
        }

        // 역추적 결과이므로 뒤집어서 출력 (이미 오름차순 정렬된 상태로 들어감)
        reverse(path.begin(), path.end());
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << (i == path.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}