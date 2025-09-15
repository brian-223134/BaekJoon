#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> dist(N+1, vector<int>(N+1, 100));
    // 자기 자신은 0
    for (int i = 1; i <= N; ++i) dist[i][i] = 0;

    // 친구 관계 입력
    while (true) 
    {
        int a, b;
        cin >> a >> b;
        if (a == -1 && b == -1) break;
        dist[a][b] = dist[b][a] = 1;
    }

    // 플로이드-워셜
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    // 점수 계산
    vector<int> score(N+1);
    int minScore = 100;
    for (int i = 1; i <= N; ++i) 
    {
        score[i] = *max_element(dist[i].begin() + 1, dist[i].end());
        minScore = min(minScore, score[i]);
    }

    // 후보자 찾기
    vector<int> candidates;
    for (int i = 1; i <= N; ++i)
        if (score[i] == minScore) candidates.push_back(i);

    // 출력
    cout << minScore << " " << candidates.size() << "\n";
    for (int c : candidates) cout << c << " ";
    return 0;
}