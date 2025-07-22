#include <iostream>
#include <algorithm>

using namespace std;

int n;
int map[11][11];
bool visited[11];
int answer = 1e9; // ����� ū ������ �ʱ�ȭ

void dfs(int start, int curr, int depth, int cost) 
{
    // ���� ����: ��� ���ø� �湮�߰�, ���������� ���ƿ� �� ���� ��
    if (depth == n && map[curr][start] > 0) 
    {
        answer = min(answer, cost + map[curr][start]);
        return;
    }

    for (int next = 0; next < n; ++next) 
    {
        if (!visited[next] && map[curr][next] > 0) 
        {
            visited[next] = true;
            dfs(start, next, depth + 1, cost + map[curr][next]);
            visited[next] = false; // ��Ʈ��ŷ
        }
    }
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> map[i][j];

    // �� ���ø� ���������� �Ͽ� DFS ����
    for (int i = 0; i < n; ++i) {
        fill(visited, visited + n, false);
        visited[i] = true;
        dfs(i, i, 1, 0); // start, current, depth, cost
    }

    cout << answer << '\n';
    return 0;
}