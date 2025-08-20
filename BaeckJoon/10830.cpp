#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

long long N;
long long B;
const int MOD = 1000;
using matrix = vector<vector<long long>>;

matrix multiply(const matrix& A, const matrix& B)
{
    matrix C(N, vector<long long>(N, 0));
    for (int i = 0; i < N; ++i) 
    {
        for (int j = 0; j < N; ++j) 
        {
            for (int k = 0; k < N; ++k) 
            {
                C[i][j] += A[i][k] * B[k][j];
            }
            C[i][j] %= MOD;
        }
    }
    return C;
}

matrix power(matrix A, long long B) 
{
    // B�� 1�̸� A�� ��ȯ
    if (B == 1) 
    {
        // �Է����� ���� ��� A�� ���ҵ鵵 1000���� ������� ��
        for (int i = 0; i < N; ++i) 
        {
            for (int j = 0; j < N; ++j)
            {
                A[i][j] %= MOD;
            }
        }
        return A;
    }

    // B�� 2�� ���� ���� ���� ��� ȣ��
    matrix half = power(A, B / 2);

    // half * half ��� (A^(B/2) * A^(B/2))
    matrix result = multiply(half, half);

    // B�� Ȧ���̸� A�� �� �� �� ������
    if (B % 2 == 1) 
    {
        result = multiply(result, A);
    }

    return result;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);


    cin >> N >> B;

    matrix A(N, vector<long long>(N));
    for (int i = 0; i < N; ++i) 
    {
        for (int j = 0; j < N; ++j) 
        {
            cin >> A[i][j];
        }
    }

    matrix result = power(A, B);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
