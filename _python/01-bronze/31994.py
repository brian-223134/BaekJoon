best_name = ""
best_score = -1

for _ in range(7):
    name, score = input().split()
    score = int(score)
    if score > best_score:
        best_score = score
        best_name = name

print(best_name)