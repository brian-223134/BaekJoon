#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


const int MAX = 1000001;
vector<int> adj[MAX];
int dp[MAX][2]; 
// DP ���̺�: dp[i][j]�� i�� ��带 ��Ʈ�� �ϴ� ����Ʈ������ �ּ� �󸮾���� ��
// j=0: i�� ��尡 �󸮾���Ͱ� �ƴ� ���
// j=1: i�� ��尡 �󸮾������ ���
bool visited[MAX];

void dfs(int u) 
{
    visited[u] = true;

    // 1. ���� ��� u�� �󸮾������ ��� (dp[u][1])
    // u�� �󸮾�����̹Ƿ�, �ڱ� �ڽ� ���� 1������ ����
    dp[u][1] = 1;
    // u�� �ڽ� ���� �󸮾�����̵� �ƴϵ� ������� (u�� ���̵� ���������Ƿ�)
    // ���� �ڽ� ����� �� ���(�󸮾�����̰ų� �ƴ� ���) �� �ּҰ��� ����

    // 2. ���� ��� u�� �󸮾���Ͱ� �ƴ� ��� (dp[u][0])
    // u�� �󸮾���Ͱ� �ƴϹǷ�, 0������ ����
    dp[u][0] = 0;
    // u�� ���̵� ���Ĺ�������, u�� ��� �ڽ� ���� �ݵ�� �󸮾���Ϳ��� ��
    // ���� �ڽ� ��尡 �󸮾������ ���(dp[v][1])�� ���� ����

    for (int v : adj[u])
    {
        if (!visited[v]) 
        { 
            // u�� �ڽ� ��� v�� ���� ��� ȣ��
            dfs(v); // ���� ������ �������� DP ���� ����ϰ� ���ƿ�

            // �ڽ� ��� v�� ���� DP ���� u�� DP ���� �ݿ�

            // u�� �󸮾����(1)�� ���: 
            // v�� �󸮾�����̵� �ƴϵ� ��������Ƿ�, min(dp[v][0], dp[v][1])�� ����
            dp[u][1] += min(dp[v][0], dp[v][1]);

            // u�� �󸮾���Ͱ� �ƴ� ���(0): 
            // v�� �ݵ�� �󸮾���Ϳ��� �ϹǷ�, dp[v][1]�� ����
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

    // ��Ʈ ���(1)�� �󸮾������ ���(dp[1][1])�� 
    // �󸮾���Ͱ� �ƴ� ���(dp[1][0]) �� �ּڰ��� ���� ��
    cout << min(dp[1][0], dp[1][1]) << "\n";

    return 0;
}