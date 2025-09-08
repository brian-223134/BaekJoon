#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
typedef struct egg {
    int s, w; // s: ������, w: ����
} egg;

vector<egg> eggs(300);
int answer = 0;

void solution(int index)
{
    if (index == n)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (eggs[i].s <= 0) cnt++;
        answer = max(answer, cnt);
        return;
    }
    if (eggs[index].s <= 0) // �̹� ���� ����̸� ���� �������
    {
        solution(index + 1);
        return;
    }
    bool hit = false;
    for (int i = 0; i < n; i++)
    {
        if (i == index || eggs[i].s <= 0) continue; // �ڱ� �ڽ��̰ų� �̹� ���� ����� �н�
        hit = true;
        eggs[index].s -= eggs[i].w;
        eggs[i].s -= eggs[index].w;
        solution(index + 1);
        eggs[index].s += eggs[i].w;
        eggs[i].s += eggs[index].w;
    }
    if (!hit) // �� �� �ִ� ����� ������ ���� �������
        solution(index + 1);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> eggs[i].s >> eggs[i].w;
    }

    solution(0);
    cout << answer;
    return 0;
}