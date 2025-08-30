#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// students: 각 학생이 선택한 학생 배열
// visited: 현재 DFS 경로상에 있는지 여부
// finished: 해당 학생에 대한 탐색이 완전히 종료되었는지 여부
// team_members_count: 팀을 이룬 학생 수
int students[100001];
bool visited[100001];
bool finished[100001];
int team_members_count;

void dfs(int current_node) 
{
    visited[current_node] = true; // '방문 중' 상태로 변경
    int next_node = students[current_node];

    if (!visited[next_node]) 
    {
        // 다음 노드가 아직 방문 전이라면 탐색 계속
        dfs(next_node);
    }
    else if (!finished[next_node]) 
    {
        // 다음 노드가 '방문 중' 상태라면 사이클 발견
        // next_node 부터 사이클이 시작됨
        // 자기 자신을 포함하여 팀원 수 카운트
        for (int node = next_node; node != current_node; node = students[node])
        {
            team_members_count++;
        }
        team_members_count++; // 자기 자신(current_node) 카운트
    }
    // else if (finished[next_node]) 는 이미 탐색이 끝난 노드를 만난 경우로,
    // 현재 경로는 팀을 이룰 수 없으므로 아무 작업도 하지 않음.

    finished[current_node] = true; // 현재 노드에 대한 탐색 완료
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

        // 초기화
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