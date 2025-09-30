#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n;
vector<int> inorder, postorder;
unordered_map<int, int> inorder_idx;

void buildPreorder(int in_start, int in_end, int post_start, int post_end) 
{
    if (in_start > in_end || post_start > post_end) return;

    int root = postorder[post_end];
    cout << root << ' ';

    int root_idx = inorder_idx[root];
    int left_size = root_idx - in_start;

    // 왼쪽 서브트리
    buildPreorder(in_start, root_idx - 1, post_start, post_start + left_size - 1);
    // 오른쪽 서브트리
    buildPreorder(root_idx + 1, in_end, post_start + left_size, post_end - 1);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    inorder.resize(n);
    postorder.resize(n);

    for (int i = 0; i < n; i++) 
    {
        cin >> inorder[i];
        inorder_idx[inorder[i]] = i;
    }
    for (int i = 0; i < n; i++) 
    {
        cin >> postorder[i];
    }

    buildPreorder(0, n - 1, 0, n - 1);

    return 0;
}
