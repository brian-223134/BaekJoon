#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 문자가 이미 벡터에 있는지 확인하고 빈도를 높이는 함수
bool is_in(vector<pair<char, int>>& temp, char c)
{
    for (auto& i : temp)
    {
        if (i.first == c)
        {
            i.second += 1;
            return true;
        }
    }
    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n;
    cin >> n;

    vector<pair<char, int>> v;
    for (int i = 0; i < n.length(); i++)
    {
        if (!is_in(v, n[i]))
        {
            v.push_back({ n[i], 1 });
        }
    }

    // 사전순 출력을 위해 정렬
    sort(v.begin(), v.end());

    int odd_cnt = 0;
    char mid_char = 0;
    string head = "";

    for (const auto& i : v)
    {
        // 홀수 개인 문자가 있는지 확인
        if (i.second % 2 == 1)
        {
            odd_cnt++;
            mid_char = i.first;
        }

        // 각 문자의 절반만큼만 head에 추가
        for (int j = 0; j < i.second / 2; j++) {
            head += i.first;
        }
    }

    // 홀수 개인 문자가 2개 이상이면 팰린드롬을 만들 수 없음
    if (odd_cnt > 1)
    {
        cout << "I'm Sorry Hansoo\n";
        return 0;
    }

    // 뒷부분은 앞부분을 뒤집은 것
    string tail = head;
    reverse(tail.begin(), tail.end());

    // 전체 결과: 앞부분 + (가운데 문자) + 뒷부분
    string result = head;
    if (odd_cnt == 1) result += mid_char;
    result += tail;

    cout << result << "\n";

    return 0;
}