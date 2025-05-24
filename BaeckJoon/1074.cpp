#include<iostream>

using namespace std;

int Z(int n, int r, int c)
{
    if (n == 0) return 0; // 1x1일 때는 순서 0

    int half = 1 << (n - 1); // 한 변의 절반 크기
    int size = half * half;

    // 사분면 결정 및 offset 계산
    if (r < half && c < half) return Z(n - 1, r, c);               // 1사분면
    if (r < half && c >= half) return size + Z(n - 1, r, c - half); // 2사분면
    if (r >= half && c < half) return 2 * size + Z(n - 1, r - half, c); // 3사분면
    return 3 * size + Z(n - 1, r - half, c - half);                   // 4사분면
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