#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
    - 문자열이 폭발 문자열을 포함하고 있는 경우에, 모든 폭발 문자열이 폭발하게 된다.
      남은 문자열을 순서대로 이어 붙여 새로운 문자열을 만든다.
    - 새로 생긴 문자열에 폭발 문자열이 포함되어 있을 수도 있다.
    - 폭발은 폭발 문자열이 문자열에 없을 때까지 계속된다.
*/

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, bomb;
    cin >> s >> bomb;
    const int blen = static_cast<int>(bomb.size());

    // 결과를 쌓아갈 스택 역할의 동적 배열
    vector<char> st;
    st.reserve(s.size());

    for (char c : s)
    {
        st.push_back(c); // 한 글자씩 스택에 추가

        // 스택 끝부분 길이가 bomb보다 길거나 같을 때만 패턴 확인
        if (static_cast<int>(st.size()) >= blen)
        {
            bool match = true;
            // 폭발 문자열과 끝부분이 동일한지 확인
            for (int i = 0; i < blen; ++i)
            {
                if (st[st.size() - blen + i] != bomb[i])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                // 동일하면 bomb 길이만큼 제거하여 폭발 처리
                for (int i = 0; i < blen; ++i) st.pop_back();
            }
        }
    }

    if (st.empty())
        cout << "FRULA";
    else
        cout << string(st.begin(), st.end());

    return 0;
}