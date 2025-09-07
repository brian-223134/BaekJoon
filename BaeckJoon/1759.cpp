#include <iostream>
#include <algorithm>
using namespace std;

int l, c;
char letter[15];
char words[15];
char vowel[5] = { 'a', 'e', 'i', 'o', 'u' };

bool is_vowel(char c) 
{
    for (int i = 0; i < 5; i++)
        if (c == vowel[i]) return true;
    return false;
}

// depth: 현재까지 선택한 문자 개수, start: 탐색을 재개할 시작 위치
void solution(int depth, int start, int v_cnt, int c_cnt)
{
    if (depth == l) 
    {
        if (v_cnt >= 1 && c_cnt >= 2) 
        {
            for (int i = 0; i < l; i++)
                cout << words[i];
            cout << '\n';
        }
        return;
    }
    for (int i = start; i < c; i++) 
    {
        words[depth] = letter[i];
        if (is_vowel(letter[i]))
            solution(depth + 1, i + 1, v_cnt + 1, c_cnt);
        else
            solution(depth + 1, i + 1, v_cnt, c_cnt + 1);
    }
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> l >> c;
    for (int i = 0; i < c; i++)
        cin >> letter[i];

    sort(letter, letter + c);

    solution(0, 0, 0, 0);

    return 0;
}