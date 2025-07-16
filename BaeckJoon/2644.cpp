#include <iostream>
#include <vector>

using namespace std;

int num, a, b, rel_num;
int map[101][101];      // ���赵
bool visited[101];      // �湮 ����
int result = -1;        // �ʱⰪ -1�� ���� (�̼��� ���� �� ���� ���)

void dfs(int current, int depth) {
    if (current == b) {
        result = depth;
        return;
    }

    visited[current] = true;

    for (int i = 1; i <= num; i++) {
        if (!visited[i] && map[current][i] == 1) {
            dfs(i, depth + 1);
        }
    }
}

int main(void) 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> num;
    cin >> a >> b;
    cin >> rel_num;

    for (int i = 0; i < rel_num; i++) {
        int x, y;
        cin >> x >> y;
        map[x][y] = 1;
        map[y][x] = 1;
    }

    dfs(a, 0);
    cout << result << '\n';
    return 0;
}