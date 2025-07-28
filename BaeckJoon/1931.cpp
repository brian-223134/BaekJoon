#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    vector<tuple<int, int>> meeting;

    for (int i = 0; i < t; i++)
    {
        int start, end;
        cin >> start >> end;
        meeting.push_back({ start, end });
    }

    // 끝나는 시간 빠른 순 → 같으면 시작 시간 빠른 순
    sort(meeting.begin(), meeting.end(), [](const tuple<int, int>& a, const tuple<int, int>& b) {
        if (get<1>(a) == get<1>(b))
            return get<0>(a) < get<0>(b);
        return get<1>(a) < get<1>(b);
        });

    int result = 0;
    int end_time = 0;

    for (int i = 0; i < t; i++) 
    {
        int start = get<0>(meeting[i]);
        int end = get<1>(meeting[i]);
        if (start >= end_time) 
        {
            result++;
            end_time = end;
        }
    }

    cout << result;
    return 0;
}