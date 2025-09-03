#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
#include <cmath>

using namespace std;

int n, m; // n * n matrix, m: 치킨집 개수

typedef struct store
{
    int y, x;
} store;

typedef struct home
{
    int y, x;
} home;

vector<store> store_list;
vector<home> home_list;
vector<store> chosen_stores; // M개의 치킨집 조합을 임시로 저장할 벡터

// 초기 최솟값은 매우 큰 값으로 설정
int result = 987654321;

// 집과 치킨집 사이의 거리를 계산하는 함수
int chicken_dis(store s, home h)
{
    return abs(s.y - h.y) + abs(s.x - h.x);
}

// 도시의 치킨 거리를 계산하는 함수
void calculate_city_distance()
{
    int current_city_dist = 0;
    // 모든 집에 대해서
    for (int i = 0; i < home_list.size(); ++i)
    {
        int single_home_dist = 987654321;
        // 선택된 M개의 치킨집 중 가장 가까운 거리를 찾음
        for (int j = 0; j < chosen_stores.size(); ++j)
        {
            single_home_dist = min(single_home_dist, chicken_dis(chosen_stores[j], home_list[i]));
        }
        current_city_dist += single_home_dist;
    }
    // 도시 치킨 거리의 최솟값을 갱신
    result = min(result, current_city_dist);
}

// 백트래킹으로 M개의 치킨집을 고르는 모든 조합을 탐색하는 함수
// start_idx: 탐색을 시작할 store_list의 인덱스
// count: 현재까지 선택한 치킨집의 개수
void combination(int start_idx, int count)
{
    // 1. 종료 조건: M개의 치킨집을 모두 선택했다면
    if (count == m)
    {
        // 현재 조합으로 도시의 치킨 거리를 계산하고 최솟값을 갱신
        calculate_city_distance();
        return;
    }

    // 2. 재귀 호출: 치킨집을 선택하고 다음 단계로 진행
    for (int i = start_idx; i < store_list.size(); ++i)
    {
        // 2-1. 선택 (Choose)
        chosen_stores.push_back(store_list[i]);
        // 2-2. 탐색 (Explore)
        combination(i + 1, count + 1);
        // 2-3. 선택 해제 (Un-choose / Backtrack)
        chosen_stores.pop_back();
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    // arr 벡터는 main 함수 내에서만 사용되므로 전역으로 둘 필요가 없습니다.
    // vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int input;
            cin >> input;
            if (input == 1)
            {
                home_list.push_back({ i,j });
            }
            else if (input == 2)
            {
                store_list.push_back({ i,j });
            }
        }
    }

    // 백트래킹 시작: 0번 인덱스부터, 0개를 선택한 상태로 시작
    combination(0, 0);

    cout << result << "\n";

    return 0;
}