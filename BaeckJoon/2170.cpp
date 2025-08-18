#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> lines(n);
    for (int i = 0; i < n; i++)
    {
        cin >> lines[i].first >> lines[i].second;
    }

    // 선들을 시작점을 기준으로 오름차순 정렬
    sort(lines.begin(), lines.end());

    // long long으로 총 길이를 저장하여 오버플로우 방지
    long long total_length = 0;

    // 첫 번째 선을 기준으로 초기 병합 구간 설정
    int start = lines[0].first;
    int end = lines[0].second;

    for (int i = 1; i < n; i++)
    {
        // 다음 선의 시작점이 현재 병합 구간 안에 있는 경우 (선이 겹치는 경우)
        if (lines[i].first <= end)
        {
            // 병합 구간의 끝점을 더 먼 쪽으로 갱신
            end = max(end, lines[i].second);
        }
        // 다음 선이 현재 병합 구간과 완전히 떨어진 경우
        else
        {
            // 지금까지 병합된 구간의 길이를 총 길이에 더함
            total_length += (end - start);
            // 새로운 병합 구간을 시작
            start = lines[i].first;
            end = lines[i].second;
        }
    }

    // 루프가 끝난 후 마지막으로 병합된 구간의 길이를 더해줌
    total_length += (end - start);

    cout << total_length;

    return 0;
}