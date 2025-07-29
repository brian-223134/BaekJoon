#include <iostream>
using namespace std;

int paper[129][129];
int n;
int blue, white;

void divide(int y, int x, int size)
{
    int color = paper[y][x];
    bool flag_same = true;

    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            if (paper[i][j] != color) 
            {
                flag_same = false;
                break;
            }
        }
        if (!flag_same) break;
    }

    if (flag_same) 
    {
        if (color == 1) blue++;
        else white++;
        return;
    }

    int half = size / 2;
    divide(y, x, half);
    divide(y, x + half, half);
    divide(y + half, x, half);
    divide(y + half, x + half, half);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> paper[i][j];
        }
    }

    blue = white = 0;
    divide(0, 0, n);
    cout << white << '\n' << blue;

    return 0;
}