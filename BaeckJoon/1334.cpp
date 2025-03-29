#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int i, j;
    string input;
    cin >> input;

    if (input.length() == 1) 
    { 
        if (input == "9")
            input = "11";
        else    
            input[0] += 1;
        cout << input << endl;
        return 0;
    }
    for (i = 0; i < input.length(); i++) 
    {
        if (input[i] != '9') 
            break;
        if (i == input.length() - 1) 
        { 
            string tmp;
            tmp += "1";
            for (i = 0; i < input.length() - 1; i++)
                tmp += "0";
            tmp += "1";
            cout << tmp << "\n";
            return 0;
        }
    }
    for (i = input.length() / 2 - 1; i >= 0; i--) 
    { 
        if (input[i] > input[input.length() - 1 - i]) 
        { 
            for (j = 0; j < input.length() / 2; j++)
                input[input.length() - 1 - j] = input[j];
            cout << input << "\n";
            return 0;
        }
        string tmp = input;
        reverse(tmp.begin(), tmp.end());
        if (input[i] < input[input.length() - 1 - i]
            || !(tmp.substr(tmp.length() / 2, tmp.length() / 2 + input.length() % 2).compare(input.substr(input.length() / 2, input.length() / 2 + input.length() % 2)))) 
        { 
            for (j = input.length() / 2 - 1 + input.length() % 2; j >= 0; j--) 
            { 
                if (input[j] != '9')
                    break;
                input[j] = '0';
            }
            input[j] += 1;
            for (j = 0; j < input.length() / 2; j++) 
            {
                input[input.length() - 1 - j] = input[j];
            }
            cout << input << "\n";
            return 0;
        }
    }
    return 0;
}