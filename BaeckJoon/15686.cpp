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

int n, m; // n * n matrix, m: ġŲ�� ����

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
vector<store> chosen_stores; // M���� ġŲ�� ������ �ӽ÷� ������ ����

// �ʱ� �ּڰ��� �ſ� ū ������ ����
int result = 987654321;

// ���� ġŲ�� ������ �Ÿ��� ����ϴ� �Լ�
int chicken_dis(store s, home h)
{
    return abs(s.y - h.y) + abs(s.x - h.x);
}

// ������ ġŲ �Ÿ��� ����ϴ� �Լ�
void calculate_city_distance()
{
    int current_city_dist = 0;
    // ��� ���� ���ؼ�
    for (int i = 0; i < home_list.size(); ++i)
    {
        int single_home_dist = 987654321;
        // ���õ� M���� ġŲ�� �� ���� ����� �Ÿ��� ã��
        for (int j = 0; j < chosen_stores.size(); ++j)
        {
            single_home_dist = min(single_home_dist, chicken_dis(chosen_stores[j], home_list[i]));
        }
        current_city_dist += single_home_dist;
    }
    // ���� ġŲ �Ÿ��� �ּڰ��� ����
    result = min(result, current_city_dist);
}

// ��Ʈ��ŷ���� M���� ġŲ���� ���� ��� ������ Ž���ϴ� �Լ�
// start_idx: Ž���� ������ store_list�� �ε���
// count: ������� ������ ġŲ���� ����
void combination(int start_idx, int count)
{
    // 1. ���� ����: M���� ġŲ���� ��� �����ߴٸ�
    if (count == m)
    {
        // ���� �������� ������ ġŲ �Ÿ��� ����ϰ� �ּڰ��� ����
        calculate_city_distance();
        return;
    }

    // 2. ��� ȣ��: ġŲ���� �����ϰ� ���� �ܰ�� ����
    for (int i = start_idx; i < store_list.size(); ++i)
    {
        // 2-1. ���� (Choose)
        chosen_stores.push_back(store_list[i]);
        // 2-2. Ž�� (Explore)
        combination(i + 1, count + 1);
        // 2-3. ���� ���� (Un-choose / Backtrack)
        chosen_stores.pop_back();
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    // arr ���ʹ� main �Լ� �������� ���ǹǷ� �������� �� �ʿ䰡 �����ϴ�.
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

    // ��Ʈ��ŷ ����: 0�� �ε�������, 0���� ������ ���·� ����
    combination(0, 0);

    cout << result << "\n";

    return 0;
}