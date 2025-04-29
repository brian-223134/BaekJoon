#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char map[20][20];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int r, c;
    cin >> r >> c; //세로, 가로
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
        }
    }

    vector<string> word;
    string temp;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (map[i][j] != '#')
            {
                temp += map[i][j];
            }
            else //금지 구역을 만났을 때
            {
                if (!temp.empty()) word.push_back(temp);
                temp.clear();
            }
        }
        if (!temp.empty()) word.push_back(temp);
        temp.clear();
    }

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            if (map[j][i] != '#')
            {
                temp += map[j][i];
            }
            else //금지 구역을 만났을 때
            {
                if (!temp.empty()) word.push_back(temp);
                temp.clear();
            }
        }
        if (!temp.empty()) word.push_back(temp);
        temp.clear();
    }

    word.erase(
        remove_if(word.begin(), word.end(), [](const string& s) {
            return s.length() == 1;
            }),
        word.end()
    );

    sort(word.begin(), word.end());
    cout << word[0];
}