from collections import Counter

n = int(input().strip())
base = input().strip()
base_counter = Counter(base)

answer = 0

for _ in range(n - 1):
    word = input().strip()
    current_counter = Counter(word)

    pos = 0
    neg = 0

    for ch in set(base_counter) | set(current_counter):
        diff = current_counter[ch] - base_counter[ch]
        if diff > 0:
            pos += diff
        elif diff < 0:
            neg += -diff

    if pos <= 1 and neg <= 1:
        answer += 1

print(answer)