#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<pair<int, int>> input;
    vector<int> distance;
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int a, b;
        int temp_dis;
        cin >> a >> b;
        temp_dis = b - a;
        input.push_back({ a, b });
        distance.push_back(temp_dis);
    }

    if (distance.size() % 2 == 1)
    {
        cout << 1;
        return 0;
    }
    else //vector의 개수가 짝수 개일 때 여러 개가 발생
    {
        sort(distance.begin(), distance.end());
        int start_pos, end_pos;
        end_pos = distance.size() / 2;
        start_pos = end_pos - 1;
        cout << distance[end_pos] - distance[start_pos] + 1;
        return 0;
    }
}