#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int lcs[1001][1001]; // LCS 문자 길이 저장
string a, b; // 비교할 문자열

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> a;
    cin >> b;
    
    int len_a = a.length();
    int len_b = b.length();

    int result = 0;

    for (int i = 0; i <= len_a; i++)
    {
        for (int j = 0; j <= len_b; j++)
        {
            if (i == 0 || j == 0)
            {
                lcs[i][j] = 0;
            }
            else if (i != 0 && j != 0 && a[i - 1] == b[j - 1])
            {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
                if (result < lcs[i][j]) result = lcs[i][j];
            }
            else
            {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                if (result < lcs[i][j]) result = lcs[i][j];
            }
        }
    }

    cout << result;
    return 0;
}