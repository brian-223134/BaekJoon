#include <iostream>
#include <string>
#include <stack>

using namespace std;

// ������ �켱������ ��ȯ�ϴ� �Լ�
int precedence(char op) 
{
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0; // ��ȣ�� �켱������ ���� ����
}

// ���� ǥ����� ���� ǥ������� ��ȯ
string infixToPostfix(string infix) 
{
    stack<char> s;
    string postfix = ""; // ����� ������ ���ڿ�

    for (char& ch : infix) 
    {
        // 1. �ǿ������� ���
        if (isalpha(ch) || isdigit(ch)) 
        {
            postfix += ch;
        }
        // 2. ���� ��ȣ�� ���
        else if (ch == '(') 
        {
            s.push(ch);
        }
        // 3. �ݴ� ��ȣ�� ���
        else if (ch == ')') 
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // '(' ����
        }
        // 4. �������� ���
        else {
            while (!s.empty() && precedence(ch) <= precedence(s.top())) 
            {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    // ���ÿ� �����ִ� ��� �����ڸ� ����� �߰�
    while (!s.empty()) 
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    string input;
    cin >> input;
    cout << infixToPostfix(input);

    return 0;
}