#include <iostream>
#include <vector>

int N;
using namespace std;
vector <int> Get;
bool Check[50001] = { false, };

void MakeGet() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int X;
        std::cin >> X;
        Get.push_back(X);
    }
}

void Explosion(int Index) {
    Check[Index] = true;
    if (Index - 1 >= 0) {
        if (Get[Index] > Get[Index - 1] && Check[Index - 1] == false) {
            return Explosion(Index - 1);
        }
    }
    if (Index + 1 < N) {
        if (Get[Index] > Get[Index + 1] && Check[Index + 1] == false) {
            return Explosion(Index + 1);
        }
    }
}

void Solve() {
    if (Get.size() == 1) {
        cout << 1 << endl;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            if (Get[i] >= Get[i + 1]) {
                cout << i + 1 << endl;
                Explosion(i);
            }
        }
        else if (i == N - 1) {
            if (Get[i] >= Get[i - 1]) {
                cout << i + 1 << endl;
                Explosion(i);
            }
        }
        else {
            if (Get[i] >= Get[i - 1] && Get[i] >= Get[i + 1]) {
                cout << i + 1 << endl;
                Explosion(i);
            }
        }
    }
}

int main() {
    MakeGet();
    Solve();
}