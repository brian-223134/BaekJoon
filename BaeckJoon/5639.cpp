#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> preorder_result;


void postorder(int start, int end) 
{
    // 1. ���� ����: ���� �ε����� �� �ε����� �Ѿ�� �� ����Ʈ���̹Ƿ� ����
    if (start > end) 
    {
        return;
    }

    // 2. ���� ����Ʈ���� ��Ʈ ���� ���� ��ȸ �迭�� ù ��° ��
    int root_value = preorder_result[start];

    // 3. ������ ����Ʈ���� ���� ���� ã�� (���� ����)
    // ���� �˻� Ʈ���� Ư¡: ��Ʈ���� ū ù ��° ���� ������ ����Ʈ���� ������
    int right_start_index = start + 1;

    // root_value���� ũ�ų�, ���� ����(end)�� ��� ������ right_start_index ����
    while (right_start_index <= end && preorder_result[right_start_index] < root_value) 
    {
        right_start_index++;
    }

    // right_start_index�� ����Ű�� ��ġ���� ������ ����Ʈ���� ���۵�

    // 4. ���� ����Ʈ�� ��� ȣ�� (���� ����Ʈ�� ����: start+1 ���� right_start_index-1)
    // ���� ����Ʈ��: [start+1, right_start_index - 1]
    postorder(start + 1, right_start_index - 1);

    // 5. ������ ����Ʈ�� ��� ȣ�� (������ ����Ʈ�� ����: right_start_index ���� end)
    // ������ ����Ʈ��: [right_start_index, end]
    postorder(right_start_index, end);

    // 6. ��Ʈ ��� ��� (���� ��ȸ�� ����: ���� -> ������ -> ��Ʈ)
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