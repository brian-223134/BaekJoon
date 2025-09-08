#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
typedef struct egg {
    int s, w; // s: 내구도, w: 무게
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
    if (eggs[index].s <= 0) // 이미 깨진 계란이면 다음 계란으로
    {
        solution(index + 1);
        return;
    }
    bool hit = false;
    for (int i = 0; i < n; i++)
    {
        if (i == index || eggs[i].s <= 0) continue; // 자기 자신이거나 이미 깨진 계란은 패스
        hit = true;
        eggs[index].s -= eggs[i].w;
        eggs[i].s -= eggs[index].w;
        solution(index + 1);
        eggs[index].s += eggs[i].w;
        eggs[i].s += eggs[index].w;
    }
    if (!hit) // 깰 수 있는 계란이 없으면 다음 계란으로
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