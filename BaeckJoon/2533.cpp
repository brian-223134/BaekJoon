#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


const int MAX = 1000001;
vector<int> adj[MAX];
int dp[MAX][2]; 
// DP 테이블: dp[i][j]는 i번 노드를 루트로 하는 서브트리에서 최소 얼리어답터 수
// j=0: i번 노드가 얼리어답터가 아닌 경우
// j=1: i번 노드가 얼리어답터인 경우
bool visited[MAX];

void dfs(int u) 
{
    visited[u] = true;

    // 1. 현재 노드 u가 얼리어답터인 경우 (dp[u][1])
    // u는 얼리어답터이므로, 자기 자신 포함 1명으로 시작
    dp[u][1] = 1;
    // u의 자식 노드는 얼리어답터이든 아니든 상관없음 (u가 아이디어를 전달했으므로)
    // 따라서 자식 노드의 두 경우(얼리어답터이거나 아닌 경우) 중 최소값을 더함

    // 2. 현재 노드 u가 얼리어답터가 아닌 경우 (dp[u][0])
    // u는 얼리어답터가 아니므로, 0명으로 시작
    dp[u][0] = 0;
    // u가 아이디어를 전파받으려면, u의 모든 자식 노드는 반드시 얼리어답터여야 함
    // 따라서 자식 노드가 얼리어답터인 경우(dp[v][1])의 값을 더함

    for (int v : adj[u])
    {
        if (!visited[v]) 
        { 
            // u의 자식 노드 v에 대해 재귀 호출
            dfs(v); // 리프 노드까지 내려가서 DP 값을 계산하고 돌아옴

            // 자식 노드 v에 대한 DP 값을 u의 DP 값에 반영

            // u가 얼리어답터(1)인 경우: 
            // v는 얼리어답터이든 아니든 상관없으므로, min(dp[v][0], dp[v][1])을 더함
            dp[u][1] += min(dp[v][0], dp[v][1]);

            // u가 얼리어답터가 아닌 경우(0): 
            // v는 반드시 얼리어답터여야 하므로, dp[v][1]을 더함
            dp[u][0] += dp[v][1];
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    // 루트 노드(1)가 얼리어답터인 경우(dp[1][1])와 
    // 얼리어답터가 아닌 경우(dp[1][0]) 중 최솟값이 최종 답
    cout << min(dp[1][0], dp[1][1]) << "\n";

    return 0;
}