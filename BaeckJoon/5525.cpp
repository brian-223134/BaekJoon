#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

// 문자열 P: n+1개의 I와 n개의 O로 이루어짐, I와 O가 교대로 나오는 문자열
int n, m;
string s;

string gen_p(int n)
{
    string temp = "";
    // n길이의 p_n 문자열의 경우 n/2번의 IO가 반복됨.
    // ex) n == 5인 경우, IOIOI -> IO가 2 (5/2)번 반복 후 I 추가

    for (int i = 0; i < n / 2; i++)
    {
        temp += "IO";
    }
    temp += "I";

    return temp;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    cin >> m;
    cin >> s;

    // IOIOI 패턴을 선형으로 스캔하여 카운트
    int ans = 0;
    int cnt = 0;      // 현재 연속된 "IOI" 덩어리 개수
    int i = 0;

    while (i + 2 < m)
    {
        if (s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I')
        {
            cnt++;
            if (cnt == n)
            {
                ans++;
                // 겹치는 경우를 위해 마지막 "IOI" 하나를 다음 검사로 넘김
                cnt--;
            }
            i += 2; // "IOI"를 소비했으므로 다음 가능성은 i+2부터
        }
        else
        {
            // 패턴 깨짐: 초기화하고 한 칸 전진
            cnt = 0;
            i++;
        }
    }

    cout << ans << "\n";
    
    return 0;
}