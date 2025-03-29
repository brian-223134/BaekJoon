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

// �ð��� ���� sorting�� ���� �����ϱ� ���ϰ� ��
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

        // �̹� �Խõ� ���
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

        // ���ο� �л� �߰�
        if (frames.size() < N) 
        {
            Candidate c = { student, 1, currentTime };
            frames.push_back(c);
            candidateMap[student] = c;
        }
        else {
            // ���� ��õ �� ���� ������ �л� ����
            sort(frames.begin(), frames.end(), compare);
            candidateMap.erase(frames[0].id);
            frames.erase(frames.begin());

            Candidate c = { student, 1, currentTime };
            frames.push_back(c);
            candidateMap[student] = c;
        }
    }

    // �ĺ� �л� ��ȣ�� �������� ���
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