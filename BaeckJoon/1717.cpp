#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;
// 초기에 집합이 n + 1 개 있음: {0}, {1}, ... , {n}
// m: 연산의 개수
int n, m;

// 입력 형태
// 0 a b: 합집합 -> a가 속한 집합과 b가 속한 집합을 합침
// 1 a b: 확인 -> a와 b가 동일 집합에 속해 있는 지 판정

int parent[1000001];

int find(int u)
{
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void union_set(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v) return;
    parent[u] = v;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    // parent 배열 초기화
    for (int i = 0; i <= n; i++) 
    {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int act, a, b;
        cin >> act >> a >> b;

        switch (act)
        {
            case 0: // 합집합
                union_set(a, b);
                break;

            case 1: // 확인
                if (find(a) == find(b))
                {
                    cout << "YES\n";
                }
                else
                {
                    cout << "NO\n";
                }
                break;
        }
    }

    return 0;
}