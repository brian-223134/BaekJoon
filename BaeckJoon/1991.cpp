#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>
#include <cstring>

using namespace std;

struct Node 
{
    char data;
    Node* left;
    Node* right;

    Node(char d) : data(d), left(nullptr), right(nullptr) {}
};

void insert(Node*& root, unordered_map<char, Node*>& nodes, char parent, char left, char right) 
{
    // 부모 노드가 없으면 새로 생성
    if (nodes.find(parent) == nodes.end()) 
    {
        nodes[parent] = new Node(parent);
        if (root == nullptr)
            root = nodes[parent];  // 루트 노드 설정
    }

    // 왼쪽 자식 노드 생성 및 연결
    if (left != '.') 
    {
        if (nodes.find(left) == nodes.end())
            nodes[left] = new Node(left);
        nodes[parent]->left = nodes[left];
    }

    // 오른쪽 자식 노드 생성 및 연결
    if (right != '.') 
    {
        if (nodes.find(right) == nodes.end())
            nodes[right] = new Node(right);
        nodes[parent]->right = nodes[right];
    }
}

void preorder(Node* node) 
{
    if (!node) return;
    cout << node->data;
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node* node)
{
    if (!node) return;
    inorder(node->left);
    cout << node->data;
    inorder(node->right);
}

void postorder(Node* node)
{
    if (!node) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<char>> input(n, vector<char>(3));

    for (int i = 0; i < n; i++)
    {
        cin >> input[i][0] >> input[i][1] >> input[i][2];
    }

    unordered_map<char, Node*> nodes;
    Node* root = nullptr;

    for (size_t i = 0; i < input.size(); i++) 
    {
        char parent = input[i][0];
        char left = input[i][1];
        char right = input[i][2];
        insert(root, nodes, parent, left, right);
    }

    preorder(root);
    cout << '\n';
    inorder(root);
    cout << '\n';
    postorder(root);
    cout << '\n';

    return 0;
}