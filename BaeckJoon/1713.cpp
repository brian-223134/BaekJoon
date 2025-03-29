#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Candidate {
    int id;
    int recommend;
    int time;
};

// 시간에 따른 sorting을 통해 제거하기 편하게 함
bool compare(const Candidate& a, const Candidate& b) 
{
    if (a.recommend == b.recommend) return a.time < b.time;
    return a.recommend < b.recommend;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, total;
    cin >> N >> total;

    vector<int> inputs(total);
    for (int i = 0; i < total; i++) 
    {
        cin >> inputs[i];
    }

    vector<Candidate> frames;
    map<int, Candidate> candidateMap; // id -> Candidate

    int currentTime = 0;
    for (int i = 0; i < total; i++) 
    {
        int student = inputs[i];
        currentTime++;

        // 이미 게시된 경우
        bool found = false;
        for (auto& c : frames) 
        {
            if (c.id == student) 
            {
                c.recommend++;
                candidateMap[student].recommend++;
                found = true;
                break;
            }
        }

        if (found) continue;

        // 새로운 학생 추가
        if (frames.size() < N) 
        {
            Candidate c = { student, 1, currentTime };
            frames.push_back(c);
            candidateMap[student] = c;
        }
        else {
            // 가장 추천 수 적고 오래된 학생 제거
            sort(frames.begin(), frames.end(), compare);
            candidateMap.erase(frames[0].id);
            frames.erase(frames.begin());

            Candidate c = { student, 1, currentTime };
            frames.push_back(c);
            candidateMap[student] = c;
        }
    }

    // 후보 학생 번호만 오름차순 출력
    vector<int> result;
    for (const auto& c : frames) 
    {
        result.push_back(c.id);
    }

    sort(result.begin(), result.end());
    for (int id : result) 
    {
        cout << id << " ";
    }
    cout << endl;

    return 0;
}