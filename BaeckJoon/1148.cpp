#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
#include <array>
#include <cctype>

using namespace std;

// 단어를 전처리하기 위한 정보 저장 구조체
struct WordInfo
{
    array<uint8_t, 26> freq{};
    vector<uint8_t> letters;
    uint32_t mask = 0;
    int length = 0;
};

static inline char ToLowerChar(char c)
{
    return static_cast<char>(tolower(static_cast<unsigned char>(c)));
}

static inline char ToUpperChar(char c)
{
    return static_cast<char>(toupper(static_cast<unsigned char>(c)));
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    vector<string> words;
    vector<string> boards;
    string temp;

    while (cin >> temp, temp[0] != '-')
    {
        for (char& c : temp)
        {
            c = ToLowerChar(c);
        }
        words.push_back(temp);
    }

    while (cin >> temp, temp[0] != '#')
    {
        for (char& c : temp)
        {
            c = ToLowerChar(c);
        }
        boards.push_back(temp);
    }

    // 단어 전처리: 문자 빈도, 비트마스크, 고유 문자 목록 생성
    vector<WordInfo> wordInfos;
    wordInfos.reserve(words.size());

    for (const auto& w : words)
    {
        // 문제 조건상 단어 길이는 최대 9
        if (static_cast<int>(w.size()) > 9)
        {
            continue;
        }

        WordInfo info;
        info.length = static_cast<int>(w.size());

        for (char c : w)
        {
            int idx = c - 'a';
            info.freq[idx]++;
            info.mask |= (1u << idx);
        }

        for (int i = 0; i < 26; ++i)
        {
            if (info.freq[i] > 0)
            {
                info.letters.push_back(static_cast<uint8_t>(i));
            }
        }

        wordInfos.push_back(info);
    }

    // 각 보드별로 최소/최대 출현 문자 계산
    for (const auto& board : boards)
    {
        // 보드 문자 빈도와 비트마스크 계산
        array<uint8_t, 26> boardFreq{};
        uint32_t boardMask = 0;

        for (char c : board)
        {
            int idx = c - 'a';
            boardFreq[idx]++;
            boardMask |= (1u << idx);
        }

        // 보드에서 문자별로 등장하는 유효 단어 수 집계
        array<int, 26> counts{};
        counts.fill(0);

        for (const auto& w : wordInfos)
        {
            // 단어에 보드에 없는 문자가 있으면 제외
            if ((w.mask & ~boardMask) != 0)
            {
                continue;
            }

            // 단어의 각 문자가 보드 빈도 이내인지 확인
            bool ok = true;
            for (uint8_t ch : w.letters)
            {
                if (w.freq[ch] > boardFreq[ch])
                {
                    ok = false;
                    break;
                }
            }

            if (!ok)
            {
                continue;
            }

            // 유효 단어라면 해당 단어가 포함하는 문자 카운트 증가
            for (uint8_t ch : w.letters)
            {
                counts[ch]++;
            }
        }

        // 보드에 포함된 문자들 중 최소/최대 카운트 계산
        int minCount = 1'000'000;
        int maxCount = -1;

        for (int i = 0; i < 26; ++i)
        {
            if ((boardMask & (1u << i)) == 0)
            {
                continue;
            }
            minCount = min(minCount, counts[i]);
            maxCount = max(maxCount, counts[i]);
        }

        // 최소/최대 카운트를 가진 문자들 수집
        string minLetters;
        string maxLetters;

        for (int i = 0; i < 26; ++i)
        {
            if ((boardMask & (1u << i)) == 0)
            {
                continue;
            }

            if (counts[i] == minCount)
            {
                minLetters.push_back(ToUpperChar(static_cast<char>('a' + i)));
            }
            if (counts[i] == maxCount)
            {
                maxLetters.push_back(ToUpperChar(static_cast<char>('a' + i)));
            }
        }

        // 결과 출력
        cout << minLetters << " " << minCount << " " << maxLetters << " " << maxCount << "\n";
    }

    return 0;
}