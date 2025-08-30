#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// students: �� �л��� ������ �л� �迭
// visited: ���� DFS ��λ� �ִ��� ����
// finished: �ش� �л��� ���� Ž���� ������ ����Ǿ����� ����
// team_members_count: ���� �̷� �л� ��
int students[100001];
bool visited[100001];
bool finished[100001];
int team_members_count;

void dfs(int current_node) 
{
    visited[current_node] = true; // '�湮 ��' ���·� ����
    int next_node = students[current_node];

    if (!visited[next_node]) 
    {
        // ���� ��尡 ���� �湮 ���̶�� Ž�� ���
        dfs(next_node);
    }
    else if (!finished[next_node]) 
    {
        // ���� ��尡 '�湮 ��' ���¶�� ����Ŭ �߰�
        // next_node ���� ����Ŭ�� ���۵�
        // �ڱ� �ڽ��� �����Ͽ� ���� �� ī��Ʈ
        for (int node = next_node; node != current_node; node = students[node])
        {
            team_members_count++;
        }
        team_members_count++; // �ڱ� �ڽ�(current_node) ī��Ʈ
    }
    // else if (finished[next_node]) �� �̹� Ž���� ���� ��带 ���� ����,
    // ���� ��δ� ���� �̷� �� �����Ƿ� �ƹ� �۾��� ���� ����.

    finished[current_node] = true; // ���� ��忡 ���� Ž�� �Ϸ�
}

int main(void) 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) 
    {
        int n;
        cin >> n;

        // �ʱ�ȭ
        fill(visited + 1, visited + n + 1, false);
        fill(finished + 1, finished + n + 1, false);
        team_members_count = 0;

        for (int i = 1; i <= n; i++) 
        {
            cin >> students[i];
        }

        for (int i = 1; i <= n; i++) 
        {
            if (!visited[i]) 
            {
                dfs(i);
            }
        }

        cout << n - team_members_count << "\n";
    }

    return 0;
}