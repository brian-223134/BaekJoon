#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(4, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }

    // A, B, C, D 배열 분리
    vector<int> A(n), B(n), C(n), D(n);
    for (int i = 0; i < n; i++) 
    {
        A[i] = arr[i][0];
        B[i] = arr[i][1];
        C[i] = arr[i][2];
        D[i] = arr[i][3];
    }

    // A+B, C+D의 모든 조합을 구함. A x B (cartesian product)를 이용해 원소의 모든 합 조합을 할당
    vector<int> AB, CD;
    AB.reserve(n * n);
    CD.reserve(n * n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            AB.push_back(A[i] + B[j]);
            CD.push_back(C[i] + D[j]);
        }
    }

    // CD를 정렬
    sort(CD.begin(), CD.end());

    // AB의 각 값에 대해 -AB값이 CD에 몇 개 있는지 이분 탐색
    long long answer = 0;
    for (int ab : AB)
    {
        int target = -ab;
        auto range = equal_range(CD.begin(), CD.end(), target);
        answer += range.second - range.first;
    }

    cout << answer << '\n';
    return 0;
}