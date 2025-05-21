#include <iostream>
#include <regex>

using namespace std;

int T;
string s;
regex pattern("(100+1+|01)+");

void solution()
{
    cout << (regex_match(s, pattern) ? "YES\n" : "NO\n");
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    while (T--) {
        cin >> s;
        solution();
    }

    return 0;
}