#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> preorder_result;


void postorder(int start, int end) 
{
    // 1. 기저 조건: 시작 인덱스가 끝 인덱스를 넘어가면 빈 서브트리이므로 종료
    if (start > end) 
    {
        return;
    }

    // 2. 현재 서브트리의 루트 노드는 전위 순회 배열의 첫 번째 값
    int root_value = preorder_result[start];

    // 3. 오른쪽 서브트리의 시작 지점 찾기 (분할 지점)
    // 이진 검색 트리의 특징: 루트보다 큰 첫 번째 값이 오른쪽 서브트리의 시작임
    int right_start_index = start + 1;

    // root_value보다 크거나, 현재 범위(end)를 벗어날 때까지 right_start_index 증가
    while (right_start_index <= end && preorder_result[right_start_index] < root_value) 
    {
        right_start_index++;
    }

    // right_start_index가 가리키는 위치부터 오른쪽 서브트리가 시작됨

    // 4. 왼쪽 서브트리 재귀 호출 (왼쪽 서브트리 범위: start+1 부터 right_start_index-1)
    // 왼쪽 서브트리: [start+1, right_start_index - 1]
    postorder(start + 1, right_start_index - 1);

    // 5. 오른쪽 서브트리 재귀 호출 (오른쪽 서브트리 범위: right_start_index 부터 end)
    // 오른쪽 서브트리: [right_start_index, end]
    postorder(right_start_index, end);

    // 6. 루트 노드 출력 (후위 순회의 순서: 왼쪽 -> 오른쪽 -> 루트)
    cout << root_value << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int num;

    while (cin >> num) 
    {
        preorder_result.push_back(num);
    }

    if (preorder_result.empty())
    {
        return 0;
    }

    postorder(0, preorder_result.size() - 1);

    return 0;
}