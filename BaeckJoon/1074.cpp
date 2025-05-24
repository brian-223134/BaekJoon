#include<iostream>

using namespace std;

int Z(int n, int r, int c)
{
    if (n == 0) return 0; // 1x1�� ���� ���� 0

    int half = 1 << (n - 1); // �� ���� ���� ũ��
    int size = half * half;

    // ��и� ���� �� offset ���
    if (r < half && c < half) return Z(n - 1, r, c);               // 1��и�
    if (r < half && c >= half) return size + Z(n - 1, r, c - half); // 2��и�
    if (r >= half && c < half) return 2 * size + Z(n - 1, r - half, c); // 3��и�
    return 3 * size + Z(n - 1, r - half, c - half);                   // 4��и�
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, r, c;
    cin >> N >> r >> c;
    cout << Z(N, r, c) << '\n';

    return 0;
}