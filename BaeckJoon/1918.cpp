#include <iostream>
#include <string>
#include <stack>

using namespace std;

// 연산자 우선순위를 반환하는 함수
int precedence(char op) 
{
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0; // 괄호는 우선순위가 가장 낮음
}

// 중위 표기식을 후위 표기식으로 변환
string infixToPostfix(string infix) 
{
    stack<char> s;
    string postfix = ""; // 결과를 저장할 문자열

    for (char& ch : infix) 
    {
        // 1. 피연산자인 경우
        if (isalpha(ch) || isdigit(ch)) 
        {
            postfix += ch;
        }
        // 2. 여는 괄호인 경우
        else if (ch == '(') 
        {
            s.push(ch);
        }
        // 3. 닫는 괄호인 경우
        else if (ch == ')') 
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // '(' 제거
        }
        // 4. 연산자인 경우
        else {
            while (!s.empty() && precedence(ch) <= precedence(s.top())) 
            {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    // 스택에 남아있는 모든 연산자를 결과에 추가
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